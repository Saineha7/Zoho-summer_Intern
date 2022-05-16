#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

struct numbers
{
    string mobile;
    string std;
    string landline;
}num[10];

bool flag=0;int index1=0; int index2=0;
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
                else if(temp==99 && mobileBillAmount!=0)
                {
                    cout<<"\n Current mobile bill amount: "<<mobileBillAmount<<endl;
                    cout<<"\n Enter amount to pay: ";
                    cin>>newAmount;
                    mobileBillAmount -= newAmount;
                    cout<<"\n Updated mobile bill amount: "<<mobileBillAmount<<endl;
                }
                flag=1;
            }
        }

      void addConnection(int i, string no)
      {
          if(no.length()==10)
          {
            num[i].mobile = mobileNo = no;
            cout<<"\n Mobile no: "<<mobileNo<<endl;
            cout<<"\n New mobile connection added successfully!"<<endl;
            flag=1;
          }
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
                else if(temp==99 && landlineBillAmount!=0)   // to clear off all bills due - user pays off all the standing bills
                {
                    if((no.substr(no.length()-6))==landlineNo)
                    {
                        cout<<"\n Current landline bill amount: "<<landlineBillAmount<<endl;
                        cout<<"\n Enter amount to pay: ";
                        cin>>newAmount;
                        landlineBillAmount -= newAmount;  
                        cout<<"\n Updated landline bill amount: "<<landlineBillAmount<<endl;
                    }
                }
                flag=1;
            }

        }

         void addConnection(int i, string no)
        {
          if(no.size()>=6)
          {
            stdCode = no.substr(0, (no.length()-6));
            num[i].std =  stdCode;// leave out the last 6 digits and stor the rest of the value as std code
            landlineNo = (no.substr(no.length()-6)); //  get the last 6 digits and store as landline number
            num[i].landline = landlineNo;
            cout<<"\n STD code: "<<stdCode<<endl;
            cout<<"\n Landline no: "<<landlineNo<<endl;
            cout<<"\n New landline connection added successfully!"<<endl;
            flag=1;
          }
        }
};

template <class T>
class billPayments 
{
    public:
        T obj;
    public:
        void storeConnections(int i, string no)
        {
            obj.addConnection(i,no);
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
    billPayments<mobileConnection> m[10];
    billPayments<landlineConnection> l[10];
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
            case 1: cout<<"\n Enter number of connections: ";
                    cin>>n;
                    flag=0;
                    for(int i=0;i<n;index1++,i++)
                    {
                        cout<<"\n Enter number "<<index1+1<<" :";
                        cin>>no;
                        if(no.length()==10)
                            m[index1].storeConnections(index1,no);
                        else
                            {
                                cout<<"\n Incorrect, enter a valid mobile number"<<endl;
                                break;
                            }    
                    }
                    break;

            case 2: cout<<"\n Enter number of connections: ";
                    cin>>n;flag=0;
                    for(int i=0;i<n;index2++,i++)
                    {
                        cout<<"\n Enter number along with STD code: "<<index2+1<<" :";
                        cin>>no;
                        if(no.length()>=6)
                            l[index2].storeConnections(index2,no);  
                        else{ 
                            cout<<"\n Incorrect, enter a valid landline number"<<endl;
                            break;}
                    }
                    break;

            case 3: 
                    cout<<"\n Enter number for which to pay bill: ";
                    cin>>no;flag=0;
                    for(int i=0;i<index1;i++)
                    {
                        if(num[i].mobile == no)
                            m[i].zeroBillAmount(no);
                        else if(no.length()>=6 && (num[i].landline == (no.substr(no.length()-6))))
                            l[i].zeroBillAmount(no);
                        else
                            continue;
                    }
                    for(int i=0;i<index2;i++)
                    {
                        if(num[i].mobile == no)
                            m[i].zeroBillAmount(no);
                        else if(no.length()>=6 && (num[i].landline == (no.substr(no.length()-6))))
                            l[i].zeroBillAmount(no);
                        else
                            continue;
                    }    
                    if(!flag) cout<<"\n Incorrect, enter a valid number"<<endl;
                    break;

            case 4:  
                        cout<<"\n Enter number for which to update bill: ";
                        cin>>no;flag=0;
                        for(int i=0;i<index1;i++)
                        {
                            if(num[i].mobile == no) 
                                m[i].updateBillAmount(no);
                            else if(no.length()>=6 && (num[i].landline == (no.substr(no.length()-6))))
                                l[i].updateBillAmount(no);     
                            else    
                                continue; 
                        }
                         for(int i=0;i<index2;i++)
                        {
                            if(num[i].mobile == no) 
                                m[i].updateBillAmount(no);
                            else if(no.length()>=6 && (num[i].landline == (no.substr(no.length()-6))))
                                l[i].updateBillAmount(no);     
                            else    
                                continue; 
                        }
                        if(!flag) cout<<"\n Incorrect, enter a valid number"<<endl;
                        break;
                 
            default: cout<<"\n Invalid option, enter a valid one"<<endl;        
        }
        cout<<"\n Do you want to continue(y/n): ";
        cin>>o;
    }while(o=='y');   
    return 0;
}
