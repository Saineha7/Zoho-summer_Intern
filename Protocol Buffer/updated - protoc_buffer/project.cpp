#include"consoleApplication2.cpp"
#include"note.pb.h"
#include<filesystem>
#include<algorithm>
#include <filesystem> 
#include<string>
#include<stdio.h>
#include"version.pb.h"
using std::filesystem::directory_iterator;
using namespace google::protobuf;
using namespace std;

class notepad
{
    public:
        version v; int versionNo = 0; string newName, line; int count = 0; 
    string notepadContent; int pid = 0; SignIn s; int userid = 0;

    void createNewProject(notes& n, operations& opr)
    {
        note* ref = n.add_noteobj();
        operation* ref1 = opr.add_op();
        cout << "\n Enter content to add ~" << endl;
        getline(cin >> ws, notepadContent);             // since getline() doesn't ignore whitespace use " >> ws "
        ref->set_content(notepadContent);
        cout << "\n Content added successfully!" << endl;
        ref1->set_add(notepadContent);
    }

    void createNewDetails(notes &n, string fname)
    {
        userid = s.id;
        n.set_pid(++pid);
        n.set_pname(fname);
        v.set_versionno(++versionNo);
        cout << "\n version no: " << v.versionno();
    }

    void updateProject(notes& n, string dirname)
    {
        string fname, line; int ch, lineNo; int count = 0; string newName, newLine;
        cout << "\n Enter file name to update: ";
        cin >> fname;
        if (_chdir(dirname.c_str()) == 0) cout << "\n Entered directory " << endl;
        else
            cout << "\n Failed to enter directory" << endl;
        fstream file;
        file.open(fname);
        if (file)
        {
            cout << "\n 1. Update a line" << endl;
            cout << "\n 2. Update entire document" << endl;
            cin >> ch;
            if (ch == 1)
            {
                cout << "\n Enter line to update: ";
                cin >> lineNo;
                cout << "\n line no: " << lineNo << endl;
                if (lineNo<0 ) 
                {
                    cout << "\nInvalid Line Number\n";
                    return;
                }
        
                const note& no = n.noteobj(lineNo - 1);
                cout << "Current content at - line " << lineNo << " : " << no.content() << endl;
                cout << "\n Enter content to update: ";
                getline(cin >> ws, line);
                note* noo = n.mutable_noteobj(lineNo - 1);
                noo->set_content(line);
                fstream output1(fname, ios::out | ios::trunc | ios::binary);
                n.SerializeToOstream(&output1);
                cout << "Updated content at - line " << lineNo << " : " << no.content() << endl;
                v.set_versionno(++versionNo);
                cout << "\n version no: " << v.versionno();
                   
            }
            else if (ch == 2)
            {
                RepeatedPtrField<note>* ref = n.mutable_noteobj();
                ref->DeleteSubrange(0, n.noteobj_size());

                cout << "\nEnter number of lines to insert :";
                cin >> lineNo;
                cout << "\nEnter the Content :\n";
                for (int i = 0; i < lineNo; i++)
                {
                    note* noo = n.add_noteobj();
                    getline(cin, line);
                    noo->set_content(line);
                    fstream output1(fname, ios::out | ios::trunc | ios::binary);
                    n.SerializeToOstream(&output1);
                }
                v.set_versionno(++versionNo);

            }
        }
        else
            cout << "\n No such file exists!" << endl;
    }

    void removeProject(notes &n, string dirname)
    {
        int ch, lineNo; string fname;
        cout << "\n Enter file name to update: ";
        cin >> fname;
        if (_chdir(dirname.c_str()) == 0) cout << "\n Entered directory " << endl;
        else
            cout << "\n Failed to enter directory" << endl;
        fstream file;
        file.open(fname);
        if (file)
        {
            cout << "\n 1. remove a line" << endl;
            cout << "\n 2. Remove entire document content" << endl;
            cin >> ch;
            if (ch == 1)
            {
                cout << "\n Enter line to remove: ";
                cin >> lineNo;
                if (lineNo<0 || lineNo>n.noteobj_size()) {
                    cout << "\n Invalid Line Number" <<endl;
                    return;
                }
                RepeatedPtrField<note>* ref = n.mutable_noteobj();
                ref->DeleteSubrange(lineNo - 1, 1);
                fstream output1(fname, ios::out | ios::trunc | ios::binary);
                n.SerializeToOstream(&output1);
                v.set_versionno(++versionNo);
             
            }
            else if (ch == 2)
            {
                RepeatedPtrField<note>* ref = n.mutable_noteobj();
                ref->DeleteSubrange(0, n.noteobj_size());
                fstream output1(fname, ios::out | ios::trunc | ios::binary);
                n.SerializeToOstream(&output1);
                cout << "\n contents cleared successfully!" << endl;
                v.set_versionno(++versionNo);
            }
        }
        else 
            cout << "\n No such file exists!" << endl;
    }

    void revertVersion(notes &n, string dirname, operations &opr)
    {
        int vno, i=0;
        if (opr.op_size() == 0)
            cout << "\n No changes made since the creation of file" << endl;
        else
            cout << "\n Enter the version no: ";
            cin >> vno;
            if (opr.op_size() >= (vno*5))
            {
                i = (vno * 5)-1;
                const operation& u = opr.op(i);
                cout << "\n Change made at version " << i+1 << ": " << u.add() << endl;
            }
            else
                cout << "\n Not sufficient changes made for version creation" << endl;
    }

    void dispNoteContent(notes &n)
    {
        if (n.noteobj_size() == 0) {
            cout << "\n No notes exists!" << endl;
            return;
        }
        for (int i = 0; i < n.noteobj_size(); i++)
        {
            const note& u = n.noteobj(i);
            cout << "\n line "<< i+1 <<": " << u.content() << endl;
        }
    }
 
    void dispProject(notes& n, string dirname)
    {
        for (const auto& file : directory_iterator(dirname))
            cout << file.path().filename() << endl;
    }

    void checkVersion(operations &opr)
    {
        if (opr.op_size() == 0)
            cout << "\n No changes made since the creation of file" << endl;
        else
            for (int i = 0; i < opr.op_size(); i++)
            {
                const operation& u = opr.op(i);
                cout << "\n Change " << i + 1 << ": " << u.add() << endl;
            }
    }
};

int main()
{
    notes n; int ch; notepad np; char o; string fname; operations opr;
    people p; SignIn s; string dirname;
    fstream input("UserDetails", ios::in | ios::binary);
    if (!input) 
    {
        cout << "\n File not found.Creating a new file." << endl;
    }
    else if (!p.ParseFromIstream(&input)) 
    {
        cerr << "Failed to parse address book." << endl;
        return -1;
    }
    s.checkUser(p);
    fstream output("UserDetails", ios::out | ios::trunc | ios::binary);
    if (!p.SerializeToOstream(&output)) 
    {
        cerr << "Failed to write address book." << endl;
        return -1;
    }
    input.close();
    output.close();
    const char* dirPath = s.dirName.c_str();
    dirname = s.dirName;

    do
    {
        cout << "\n 1. Create new project" << endl;
        cout << "\n 2. Update project" << endl;
        cout << "\n 3. List projects" << endl;
        cout << "\n 4. Delete project" << endl;
        cout << "\n 5. Display project" << endl;
        cout << "\n 6. Revert to a particular version" << endl;
        cout << "\n 7. check version" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1: {
            
                cout << "\n Enter file name : ";
                cin >> fname;
                if (_chdir(dirPath) == 0) cout << "\n Entered directory " << endl;
                else
                    cout << "\n Failed to enter directory" << endl;
                fstream input1(fname, ios::in | ios::binary);
                fstream input2((fname + "version"), ios::in | ios::binary);
                
                if (!input1)
                {
                    cout << "\n File not found.Creating a new file." << endl;
                    np.createNewDetails(n, fname);
                    np.createNewProject(n, opr);
                }
                else if ((!n.ParseFromIstream(&input1)&&(!opr.ParseFromIstream(&input2)))) 
                {
                    cerr << "Failed to parse " << fname << endl;
                    break;
                }
                else
                    np.createNewProject(n, opr);
                fstream output1(fname, ios::out | ios::binary);
                fstream output2(fname+"version", ios::out | ios::binary);
                if ((!n.SerializeToOstream(&output1))&&(!opr.SerializeToOstream(&output2)))
                {
                    cerr << "Failed to write project." << endl;
                    return -1;
                }
                input1.close();
                output1.close();
                break;
        }

        case 2: np.updateProject(n, dirname);
                break;

        case 3: 
                np.dispProject(n, dirname);
                break;

        case 4: np.removeProject(n, dirname);
                break;

        case 5: np.dispNoteContent(n);
                break;

        case 6: np.revertVersion(n, dirname, opr);
                break;

        case 7: np.checkVersion(opr);
            break;

        default: cout << "\n Invalid option" << endl;

        }

        cout << "\n Do you want to cont?(y/n)";
        cin >> o;
    } while (o == 'y');
    return 0;
}
