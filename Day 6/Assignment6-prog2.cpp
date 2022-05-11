#include<iostream>
using namespace std;

class prog2
{
    public:
        float nr,dr;
        void nestedTryCatch()
        {
            cout<<"\n Enter 2 no's: ";
            cin>>nr>>dr;
            try
            {
                try 
                {
                    cout<<"\n\t\t --- Inner try division ---"<<endl;
                    if(dr==0)
                    {     
                        throw dr;
                    }
                    else 
                        cout<<"\n Divison result: "<<nr/dr<<endl;
                }
                catch(float dr)
                {
                     cout<<"Division error 2: rethrown to another function"<<endl;//<<e.what();
                     throw;
                }
                cout<<"\n\t\t --- Outer try division ---"<<endl;
                if(dr==0)
                {
                    throw exception();
                }
                else
                    cout<<"\n Divison result: "<<nr/dr<<endl;
            }
            catch(const std::exception &e)
            {
                cout<<"Division error 1: "<<e.what();
            }
        }

        void reThrow()
        {
            try 
            {
               nestedTryCatch();
            }
            catch(float dr)
            {
                cout<<"\n Caught rethrown error caused by denominator "<<dr<<endl;
            }
        }
};

int main()
{
    prog2 p;
    p.reThrow();
    
    return 0;
}
