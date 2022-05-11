#include<iostream>
#include<cstring>
#include<exception> // This header has the base class exception which we have to inherit and override to create any user defined exceptions
using namespace std;

class DivisionByZero : public exception
{
    public:
    string divError()
    {
        return "Invalid division";
    }
};

class FormatMismatch : public exception
{
    public:
        string mismatchError()
        {
            return "Format mismatch";
        }
};

class HeapMemoryUnavilable : public exception
{
    public:
        string what()
        {
            return "Memory is compromised!";
        }
};

class AccessingAnInvalidString : public exception
{
    public:
        string invalidMemrory()
        {
            return "Index is Invalid";
        }
};

class AccessingAnInvalidArray : public exception
{
    public:
        string arrIndexInvalid()
        {
            return "Array index is invalid";
        }
};

class MyException : public exception
{
    public:
        string name;
        MyException(string name)
        {
            
             this->name = name;
        }

        string myExecption()
        {
            string ret = "MyException["+name+"]";
            return ret;
        }

};

class miscellaneous
{
    public:
        float nr, dr; int age;
        miscellaneous(int x, int y) : nr(x), dr(y) {}

        void division()
        {
            try
            {
                if(dr==0)
                    throw DivisionByZero();
                else
                    cout<<"Ans: "<<nr/dr<<endl;    
            }
            catch(DivisionByZero d)
            {
                cout<<d.divError()<<endl;
                cout<<"\n Exception Handling Accomplished"<<endl;
            }
        }

        void task2()
        {
            try
            {
                //0x7ffffffff
                //int *ptr = new int[0x7ffffffff];
                ptr = NULL;
                //*ptr = 7; 
                //cout<<"ptr value: "<<*ptr<<endl;
                if(ptr!=NULL)
                {
                    delete(ptr);
                    throw HeapMemoryUnavilable();//bad_alloc();
                }
                else 
                {
                    *ptr = 7; 
                    cout<<"ptr value: "<<*ptr<<endl;
                }
            }
            catch(HeapMemoryUnavilable h)//(bad_alloc &h)
            {   cout<<h.what();
                cout<<"Memory is compromised!";
            }
        } 

        // task 3
        void calculateAge()
        {
            try
            {
                cout<<"\n Enter age: ";
                cin>>age;
                if(cin.fail())
                {
                    throw FormatMismatch();
                    exit(1);
                }
                else cout<<"\n Age: "<<age;
            }
            catch(FormatMismatch f)
            {
                cout<<f.mismatchError();
                cout<<"\n Exception Handling Accomplished"<<endl;

            }
        }

        void task4()
        {
            string temp;
            try 
            {
                cout<<"\n Enter string: ";
                cin>>temp;
                int length = temp.length();int i;
                cout<<"\n Enter the index to be accessed: ";
                cin>>i;
                if(i>=length)
                    throw AccessingAnInvalidString();
                else
                    cout<<"\n Result: "<<temp[i]<<endl;    
            }
            catch(AccessingAnInvalidString a)
            {
                cout<<a.invalidMemrory();
                cout<<"\n Exception Handling Accomplished"<<endl;
            }
        }

        void task5()
        {
            int arr[5];
            try 
            {
                cout<<"\n Enter 5 array elements: ";
                for(int i=0;i<5;i++)
                    cin>>arr[i];
                int length = sizeof(arr)/sizeof(arr[0]);int i;
                cout<<"\n Enter the array index to be accessed: ";
                cin>>i;
                if(i>=length)
                    throw AccessingAnInvalidArray();
                else
                    cout<<"\n Result: "<<arr[i]<<endl;    
            }
            catch(AccessingAnInvalidArray a)
            {
                cout<<a.arrIndexInvalid();
                cout<<"\n Exception Handling Accomplished"<<endl;

            }
        }

        void task6()
        {
            MyException m("Error!");
            cout<<m.myExecption();
        }
};

int main()
{
    try
    {
        int x,y;
        cout<<"\n Enter 2 numbers to perform division: ";
        cin>>x>>y;
        miscellaneous m(x,y);
        m.division();
        m.task2();
        m.task5();
        m.task4();
        m.task6();
        m.calculateAge();
        
    }
    catch(...)
    {
        cout<<"\n Exception encountered"<<endl;
    }

    return 0;
}
