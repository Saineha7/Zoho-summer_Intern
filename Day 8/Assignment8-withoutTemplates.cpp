#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

class mobileConnection
{
    public: 
      string mobileNo;
      float mobileBillAmount=0;  

      int checkConnection(string no)
        {
            if(no==mobileNo)   // already existing connection
                return 1;  
            else
                return 0;
        }

      void addMobileConnection(string no)
      {
          if(no.length()==10)
          {
            mobileNo = no;
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
        float landlineBillAmount=0;

        int checkConnection(string no)
        {
            if(no.length()>=6){
                if((no.substr(no.length()-6))==landlineNo)
                    return 1;
                    else return 0;}
                else 
                    return 0;
        }

         void addLandlineConnection(string std, string no)
        {
          if(no.length()>=6)
          {
            stdCode = std;
            landlineNo = no;
            cout<<"\n New landline connection added successfully!"<<endl;
          }
          else
            cout<<"\n Incorrect, enter a valid landline number"<<endl;
        }
};

//template <class T>
class billPayments //: public mobileConnection, public landlineConnection
{
    public:
        mobileConnection m;
        landlineConnection l;
        float newAmount;
    public:
        //void zeroBillAmount(string no);
        void storeConnections(int x, string no, string std)
        {
            
            if((x == 1))
            {
                m.addMobileConnection(no);
                cout<<"Mobile no: "<<m.mobileNo<<endl;
                
            }
            if(x==0)
            {
                l.addLandlineConnection(std, no);
                cout<<"\n Landline std code: "<<l.stdCode<<endl;
                cout<<"Landline no: "<<l.landlineNo<<endl;
            }
        }
        void updateBillAmount(string no, string std)
        {
            if(m.checkConnection(no)==1)
            {
                cout<<"\n Current mobile bill amount: "<<m.mobileBillAmount<<endl;
                cout<<"\n Enter amount to update: ";
                cin>>newAmount;
                m.mobileBillAmount += newAmount;
                cout<<"\n Updated mobile amount: "<<m.mobileBillAmount<<endl;
            }
            else if(l.checkConnection(no)==1)
            {
                cout<<"\n Current landline bill amount: "<<m.mobileBillAmount<<endl;
                cout<<"\n Enter amount to update: ";
                cin>>newAmount;
                l.landlineBillAmount += newAmount;
                cout<<"\n Updated mobile amount: "<<l.landlineBillAmount<<endl;
            }
            else 
                cout<<"\n Invalid number, no such connection exists!"<<endl;
        }


void zeroBillAmount(string no) // obj can either be a mobile or landline
{
    cout<<"\n check 1: "<<(m.checkConnection(no)==1)<<endl;
    cout<<"\n check 2: "<<(l.checkConnection(no)==1)<<endl;
    if(m.checkConnection(no)==1)
    {
        cout<<"\n Current mobile bill amount: "<<m.mobileBillAmount<<endl;
        m.mobileBillAmount = 0;
        cout<<"\n Updated mobile bill amount: "<<m.mobileBillAmount<<endl;
    }
    else if(l.checkConnection(no)==1) 
    {
        
        cout<<"\n Current landline bill amount: "<<l.landlineBillAmount<<endl;
        l.landlineBillAmount = 0;  
        cout<<"\n Updated landline bill amount: "<<l.landlineBillAmount<<endl;
    }
    else 
        cout<<"\n Invalid number, no such connection exists!"<<endl;
}
};
int main()
{
    string no,std;   int n;billPayments b;int ch;char o;
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
                    b.storeConnections(1,no,"0");
                    break;

            case 2: cout<<"\n Enter std code: ";
                    cin>>std;
                    cout<<"\n Enter number: ";
                    cin>>no;
                    b.storeConnections(0,no,std);   
                    break;

            case 3: cout<<"\n Enter number for which to pay bill: ";
                    cin>>no;
                    b.zeroBillAmount(no);       
                    break;

            case 4: cout<<"\n Enter number for which to update bill: ";
                    cin>>no;   
                    b.updateBillAmount(no, std);
                    break;     

            default: cout<<"\n Invalid option, enter a valid one"<<endl;        
        }
        cout<<"\n Do you want to continue(y/n): ";
        cin>>o;
    }while(o=='y');   
    return 0;
    
}
