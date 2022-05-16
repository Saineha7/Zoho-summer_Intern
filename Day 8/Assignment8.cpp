#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

struct numbers
{
    string mobile;
    string std;
    string landline;
}num;

class mobileConnection
{
    public: 
      string mobileNo;
      float mobileBillAmount=0, newAmount=0;  

      void checkConnection(int temp, string no)
        {
            if(no==mobileNo)   // already existing connection
            {
                if(temp==100)
                {
                    cout<<"\n Current mobile bill amount: "<<mobileBillAmount<<endl;
                    cout<<"\n Enter amount to update: ";
                    cin>>newAmount;
                    mobileBillAmount += newAmount;
                    cout<<"\n Updated mobile amount: "<<mobileBillAmount<<endl;
                }
                else if(temp==99)
                {
                    cout<<"\n Current mobile bill amount: "<<mobileBillAmount<<endl;
                    mobileBillAmount = 0;
                    cout<<"\n Updated mobile bill amount: "<<mobileBillAmount<<endl;
                }
            }
            else
                cout<<"\n Invalid connection type!"<<endl;
        }

      void addConnection(string no)
      {
          if(no.length()==10)
          {
            num.mobile = mobileNo = no;
            cout<<"\n Mobile no: "<<mobileNo<<endl;
            cout<<"\n New mobile connection added successfully!"<<endl;
          }
          else
            cout<<"\n Incorrect, enter a valid mobile number"<<endl;
      }
};

class landlineConnection
{
    public:
        string landlineNo;
        string stdCode;    // STD code can be of any length
        float landlineBillAmount=0,newAmount=0;

        void checkConnection(int temp, string no)
        {
            if(no.length()>=6)
            {
                if(temp==100)       // to update already existing amount - add amount which user should pay
                {
                    if((no.substr(no.length()-6))==landlineNo)
                    {
                        cout<<"\n Current landline bill amount: "<<landlineBillAmount<<endl;
                        cout<<"\n Enter amount to update: ";
                        cin>>newAmount;
                        landlineBillAmount += newAmount;
                        cout<<"\n Updated landline amount: "<<landlineBillAmount<<endl;
                    }
                }
                else if(temp==99)   // to clear off all bills due - user pays off all the standing bills
                {
                    if((no.substr(no.length()-6))==landlineNo)
                    {
                        cout<<"\n Current landline bill amount: "<<landlineBillAmount<<endl;
                        landlineBillAmount = 0;  
                        cout<<"\n Updated landline bill amount: "<<landlineBillAmount<<endl;
                    }
                }
            }
            else 
                cout<<"\n Invalid connection type!"<<endl;
        }

         void addConnection(string no)
        {
          if(no.length()>=6)
          {
            num.std = stdCode = no.substr(0, (no.length()-6));      // leave out the last 6 digits and stor the rest of the value as std code
            num.landline = landlineNo = (no.substr(no.length()-6)); //  get the last 6 digits and store as landline number
            cout<<"\n STD code: "<<stdCode<<endl;
            cout<<"\n Landline no: "<<landlineNo<<endl;
            cout<<"\n New landline connection added successfully!"<<endl;
          }
          else
            cout<<"\n Incorrect, enter a valid landline number"<<endl;
        }
};

template <class T>
class billPayments 
{
    public:
        T obj;
    public:
        void storeConnections(string no)
        {
            obj.addConnection(no);
        }
        void updateBillAmount(string no)
        {
            obj.checkConnection(100,no);
        }
        void zeroBillAmount(string no) 
        {
            obj.checkConnection(99,no);  
        }
};

int main()
{
    string no,std; int n,op,ch; char o;
    billPayments<mobileConnection> m;
    billPayments<landlineConnection> l;
    do
    {
        cout<<"\n 1. Add a new mobile connection"<<endl;
        cout<<"\n 2. Add a new landline connection"<<endl;
        cout<<"\n 3. Pay bill using the connection number"<<endl;
        cout<<"\n 4. Update bill amount using the connection number"<<endl;
        cout<<"\n Enter option: ";
        cin>>ch;

        switch(ch)
        {
            case 1: cout<<"\n Enter number: ";
                    cin>>no;
                    m.storeConnections(no);
                    break;

            case 2: 
                    cout<<"\n Enter number along with STD code: ";
                    cin>>no;
                    l.storeConnections(no);   
                    break;

            case 3: cout<<"\n Enter number for which to pay bill: ";
                    cin>>no;
                    if(num.mobile == no)
                        m.zeroBillAmount(no);
                    else if(num.landline == (no.substr(no.length()-6)))
                        l.zeroBillAmount(no);
                    else
                        cout<<"\n Invalid connection type!"<<endl;      
                    break;

            case 4:  cout<<"\n Enter number for which to update bill: ";
                    cin>>no;
                    if(num.mobile == no) 
                        m.updateBillAmount(no);
                    else if(num.landline == (no.substr(no.length()-6)))
                        l.updateBillAmount(no);     
                    else
                        cout<<"\n Invalid connection type!"<<endl;    
                    break;     

            default: cout<<"\n Invalid option, enter a valid one"<<endl;        
        }
        cout<<"\n Do you want to continue(y/n): ";
        cin>>o;
    }while(o=='y');   
    return 0;  
}
