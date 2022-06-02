
//////////////////////////////// old version //////////////////////////////

#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<cctype>
#include<sys/stat.h>
#include<sys/types.h>
#include<direct.h>
#include "user.pb.h"
using namespace std;

class SignIn
{
public:
    string name, email, password, place, result = ""; string dirName;int id = 0;
    people p;

        string encrypt(string pass, int s)
    {
        for (int i = 0; i < pass.size(); i++)
        {
            if (isalnum(pass[i]))
                result += char(int(pass[i]) + 7);
        }
        return result;
    }

    bool emailCheck()
    {
        string rule = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";
        regex regexPattern(rule);
        return regex_match(email, regexPattern);
    }

    int passwordCheck(people& p, string temp)
    {
        for (int i = 0; i < p.user_size(); i++)
        {

            const person& u = p.user(i);
            if (temp == u.password() && email == u.email())
            {
                return 1;
            }
        }
        return 0;
    }

    void checkUser(people& p)
    {
        int flag = 0;
        if (p.user_size() == 0)
        {
            person* ref = p.add_user();
            cout << "\n Name : ";
            cin >> name;
            cout << "\n Email : ";
            cin >> email;
            const char* dirname = email.c_str();
            dirName = "C:\\Users\\Nallaperumal\\Desktop\\install\\Demo\\ConsoleApplication2\\ConsoleApplication2\\" + email;
            cout << "\n Password : ";
            cin >> password;
            password = encrypt(password, 7);
            cout << "\n Encrypted password: " << password << endl;
            cout << "\n Location : ";
            cin >> place;
            if (_mkdir(dirname) == 0) cout << "\n New directory created!" << endl;
            else cout << "\n Directory creation failed" << endl;
            ref->set_id(p.user_size());
            ref->set_email(email);
            ref->set_password(password);
            ref->set_name(name);
            ref->set_place(place);
        }
        else
        {
            string temp;
            cout << "\n Name : ";
            cin >> name;
            cout << "\n Email : ";
            cin >> email;
            dirName = "C:\\Users\\Nallaperumal\\Desktop\\install\\Demo\\ConsoleApplication2\\ConsoleApplication2\\" + email;
            const char* dirname = email.c_str();
            for (int i = 0; i < p.user_size(); i++)
            {
                if (!emailCheck()) { cout << "\n Invalid email id!" << endl; exit(1); }  //  valid email ?
                else  // yes means check, user already present or not
                {
                    const person& u = p.user(i);
                    if (name == u.name() && email == u.email())
                    {
                        cout << "\n Welcome back " << name << "!" << endl;
                        cout << "\n Password: ";
                        cin >> temp;
                        temp = encrypt(temp, 7);
                        if (passwordCheck(p, temp))    // valid password ?
                        {
                            flag = 1; print(p);
                            cout << "\n Directory name: " << email << endl;
                            break;
                        }
                        else
                        {
                            cout << "\n Invalid password try again!" << endl; exit(0);
                        }
                    }
                }
            }

            if (!flag)
            {
                person* ref = p.add_user();
                if (_mkdir(dirname) == 0) cout << "\n New directory created!" << endl;
                else cout << "\n Directory creation failed" << endl;
                cout << "\n Password : ";
                cin >> password;
                password = encrypt(password, 7);
                cout << "\n encryp 3: " << password << endl;
                cout << "\n Location : ";
                cin >> place;
                cout << "\n p.user_size()+1" << (p.user_size() + 1) << endl;
                ref->set_id(p.user_size());
                ref->set_email(email);
                ref->set_password(password);
                ref->set_name(name);
                ref->set_place(place);
            }
        }

    }
   
    void print(people& p) {
        for (int i = 0; i < p.user_size(); i++) {
            const person& u = p.user(i);
            cout << "\n User Details" << endl;
            cout << "\n ID: " << u.id() << endl;
            cout << "\n Name     : " << u.name();
            cout << "\n Email ID : " << u.email();
            cout << "\n Password : " << u.password();
            cout << "\n Location : " << u.place() << endl;
        }
    }
};
