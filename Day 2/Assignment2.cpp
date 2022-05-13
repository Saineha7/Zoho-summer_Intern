#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

class Bank
{
	public:
		string name, estDate, bankType;
		float intRate;
	public:
		virtual string getName()=0;
		virtual string getEstablishedDate()=0;
		virtual string BankType()=0;
		virtual void getInfo()=0;
};

class Loan
{
	public:
		virtual void getAvailableLoans() = 0;
		virtual float getInterestRate() = 0;
		virtual void docsRequired() = 0;
};

class HDFC: public Bank, Loan
{
	public:
		HDFC()
		{
			name = this->getName();
			estDate = this->getEstablishedDate();
			bankType = this->BankType();
			intRate = this->getInterestRate();
		}
		void availableLoans();
		
		string getName()
		{
			return "HDFC";
		}
		
		string getEstablishedDate()
		{
			return "1971";
		}
		
		string BankType()
		{
			return "private";
		} 
		
		void getInfo()
		{
			cout<<"\n 1. Bank Name: "<<name<<endl;
			cout<<"\n 2. Established Date: "<<estDate<<endl;
			cout<<"\n 3. Bank Type: "<<bankType<<endl;
		}
		
		void getAvailableLoans()
		{
			cout<<"\n Available loans: "<<endl;
			cout<<"\n 1. Gold loan"<<endl;
			cout<<"\n 2. Land loan"<<endl;
			cout<<"\n 3. Personal loan"<<endl;
			getInterestRate();
			docsRequired();
		}
		
		float getInterestRate()
		{
			return 5;
			cout<<"\n Interest rate is "<<intRate<<endl;
		}
		
		void docsRequired()
		{
			cout<<"Required documents: Aadhar, PAN card, Past loan details"<<endl;
		}
};

class SBI: public Bank, Loan
{
	public:
		SBI()
		{
			name = this->getName();
			estDate = this->getEstablishedDate();
			bankType = this->BankType();
			intRate = this->getInterestRate();
		}
		void availableLoans();
		
		string getName()
		{
			return "SBI";
		}
		
		string getEstablishedDate()
		{
			return "1990";
		}
		
		string BankType()
		{
			return "public";
		} 
		
		void getInfo()
		{
			cout<<"\n 1. Bank Name: "<<name<<endl;
			cout<<"\n 2. Established Date: "<<estDate<<endl;
			cout<<"\n 3. Bank Type: "<<bankType<<endl;
		}
		
		void getAvailableLoans()
		{
			cout<<"\n Available loans: "<<endl;
			cout<<"\n 1. Gold loan"<<endl;
			cout<<"\n 2. Personal loan"<<endl;
			getInterestRate();
			docsRequired();
		}
		
		float getInterestRate()
		{
			return 6;
			cout<<"\n Interest rate is "<<intRate<<endl;
		}
		
		void docsRequired()
		{
			cout<<"\n Required documents: Aadhar, PAN card"<<endl;
		}
};

class ICICI: public Bank, Loan
{
	public:
		ICICI()
		{
			name = this->getName();
			estDate = this->getEstablishedDate();
			bankType = this->BankType();
			intRate = this->getInterestRate();
		}
		void availableLoans();
		
		string getName()
		{
			return "ICICI";
		}
		
		string getEstablishedDate()
		{
			return "1941";
		}
		
		string BankType()
		{
			return "private";
		} 
		
		void getInfo()
		{
			cout<<"\n 1. Bank Name: "<<name<<endl;
			cout<<"\n 2. Established Date: "<<estDate<<endl;
			cout<<"\n 3. Bank Type: "<<bankType<<endl;
		}
		
		void getAvailableLoans()
		{
			cout<<"\n Available loans: "<<endl;
			cout<<"\n 1. Land loan"<<endl;
			cout<<"\n 2. Personal loan"<<endl;
			getInterestRate();
			docsRequired();
		}
		
		float getInterestRate()
		{
			return 7;
			cout<<"\n Interest rate is "<<intRate<<endl;
		}
		
		void docsRequired()
		{
			cout<<"Required documents: Aadhar, Past loan details"<<endl;
		}
};

class IndianBank: public Bank, Loan
{

	public:
		IndianBank()
		{
			name = this->getName();
			estDate = this->getEstablishedDate();
			bankType = this->BankType();
			intRate = this->getInterestRate();
		}
		void availableLoans();
		
		string getName()
		{
			return "Indian Bank";
		}
		
		string getEstablishedDate()
		{
			return "2007";
		}
		
		string BankType()
		{
			return "public";
		} 
		
		void getInfo()
		{
			cout<<"\n 1. Bank Name: "<<name<<endl;
			cout<<"\n 2. Established Date: "<<estDate<<endl;
			cout<<"\n 3. Bank Type: "<<bankType<<endl;
		}
		
		void getAvailableLoans()
		{
			cout<<"\n Available loans: "<<endl;
			cout<<"\n 1. Gold loan"<<endl;
			cout<<"\n 2. Land loan"<<endl;
			cout<<"\n 3. Personal loan"<<endl;
			getInterestRate();
			docsRequired();
		}
		
		float getInterestRate()
		{
			return 2;
			cout<<"\n Interest rate is "<<intRate<<endl;
		}
		
		void docsRequired()
		{
			cout<<"Required documents: Aadhar, PAN card, Past loan details"<<endl;
		}
};
string bname;

class Broker: public HDFC, SBI, ICICI, IndianBank
{
    private: 
        int x,y,z,a;
        HDFC h;SBI s;ICICI i;IndianBank ib;
	public:
	friend Bank operator<(Bank &b1, Bank &b2);
	
	void printHDFC()
	{
		HDFC c;
		c.getInfo();
		c.getAvailableLoans();
	}
	
	void printSBI()
	{
		SBI s;
		s.getInfo();
		s.getAvailableLoans();
	}
	
	void printICICI()
	{
		ICICI i;
		i.getInfo();
		i.getAvailableLoans();
	}
	
	void printIndianBank()
	{
		IndianBank ib;
		ib.getInfo();
		ib.getAvailableLoans();
	}
	
	void printAll()
	{
		printHDFC();
		printSBI();
		printICICI();
		printIndianBank();
	}

    int compare(float x, float y)
    {
        if(x==999 || y==999)
        return -1;
        if(x < y )
            return 1;
        else 
            return 2;
    }

    int compare(float x, float y, float z)
    {
        if(x==999 || y==999 || z==999)
        return -1;
        if(x < y && x < z)
            return 1;
        else if(y < x && y < z)
            return 2;   
        else
            return 3;  
    }

    int compare(float x, float y, float z, float a)
    {
        if(x==999 || y==999 || z==999 || a==999)
        return -1;
        if(x < y && x < z && x < a)
            return 1;
        else if(y < x && y < z && y < a)
            return 2;   
        else if(z < x && z < y && z < a)
            return 3; 
        else
            return 4;    
    }

    int check1(string bank1)
    {
        if(bank1=="HDFC" || bank1=="hdfc")
            return h.intRate;
        else if(bank1=="SBI" || bank1=="sbi")
            return s.intRate;
        else if(bank1=="ICICI" || bank1=="icici")
            return i.intRate;
        else if(bank1=="Indian Bank" || bank1=="indian bank")
            return ib.intRate; 
        else
            return 999;  
    }         

    int check2(string bank2)
    {
        if(bank2=="HDFC" || bank2=="hdfc")
            return h.intRate;
        else if(bank2=="SBI" || bank2=="sbi")
            return s.intRate;
        else if(bank2=="ICICI" || bank2=="icici")
            return i.intRate;
        else if(bank2=="Indian Bank" || bank2=="indian bank")
            return ib.intRate; 
         else
            return 999;
 
    } 

    int check3(string bank3)
    {
        if(bank3=="HDFC" || bank3=="hdfc")
            return h.intRate;
        else if(bank3=="SBI" || bank3=="sbi")
            return s.intRate;
        else if(bank3=="ICICI" || bank3=="icici")
            return i.intRate;
         else if(bank3=="Indian Bank" || bank3=="indian bank")
            return ib.intRate;             
        else 
            return 999;
  
    }

    int check4(string bank4)
    {
        if(bank4=="HDFC" || bank4=="hdfc")
            return h.intRate;
        else if(bank4=="SBI" || bank4=="sbi")
            return s.intRate;
        else if(bank4=="ICICI" || bank4=="icici")
            return i.intRate;
        else if(bank4=="Indian Bank" || bank4=="indian bank")
            return ib.intRate;             
        else
            return 999;
    }
	
};

int main()
{
	int ch;	char o;
	do
	{
		system("CLS");
		cout<<"\n 1. HDFC"<<endl;
		cout<<"\n 2. SBI"<<endl;
		cout<<"\n 3. ICIC"<<endl;
		cout<<"\n 4. Indian Bank"<<endl;
		cout<<"\n 5. Compare banks"<<endl;
		cout<<"\n 6. Display all banks Information: "<<endl;
		cout<<"\n Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1: {
						HDFC c;
						c.getInfo();
						c.getAvailableLoans();
						break; 
					}
			
			case 2: { 
						SBI s;
						s.getInfo();
						s.getAvailableLoans();
						break;
					}
			
			case 3: { 
						ICICI i;
						i.getInfo();
						i.getAvailableLoans();
						break;
					}
			
			case 4: {
						IndianBank ib;
						ib.getInfo();
						ib.getAvailableLoans();
						break;
					}
					
			case 5: { 
					  int n, o;Broker b;
                      string bank1, bank2, bank3, bank4;
                      cout<<"\n Available banks are: 1. HDFC 2. SBI 3. ICICI 4.Indian Bank"<<endl;
					  cout<<"\n Enter no of banks to compare: ";
					  cin>>n; 
					  if(n==2)
					  {
                        cout<<"\n Enter Bank1 name: ";
                        getline(cin >> ws, bank1);
                        cout<<"\n Enter Bank2 name: ";
                        getline(cin >> ws, bank2);   

                        o = b.compare(b.check1(bank1), b.check2(bank2));
                        if(o==1)
                            cout<<bank1<<" interest rate is cheaper than"<<bank2<<endl;
                        else if(o==2)
                            cout<<bank2<<" interest rate is cheaper than "<<bank1<<endl;   
                        else 
                            cout<<"\n Incorrect bank name - Try again!"<<endl;
					  }
					  else if(n==3)
					  {
                        cout<<"\n Enter Bank1 name: ";
                        getline(cin >> ws, bank1);
                        cout<<"\n Enter Bank2 name: ";
                        getline(cin >> ws, bank2);
                        cout<<"\n Enter Bank3 name: ";
                        getline(cin >> ws, bank3);     

                        o = b.compare(b.check1(bank1), b.check2(bank2), b.check3(bank3));
                        if(o==1)
						 cout<<bank1<<" interest rate is cheaper than"<<bank2<<" and "<<bank3<<endl;
                        else if(o==2) 
                            cout<<bank2<<" interest rate is cheaper than"<<bank1<<" and "<<bank3<<endl;
                        else if(o==3)
                            cout<<bank3<<" interest rate is cheaper than"<<bank1<<" and "<<bank2<<endl; 
                        else 
                            cout<<"\n Incorrect bank name - Try again!"<<endl;       
					  }

					  else
					  {
					  	cout<<"\n Enter Bank1 name: ";
                        getline(cin >> ws, bank1);
                        cout<<"\n Enter Bank2 name: ";
                        getline(cin >> ws, bank2);
                        cout<<"\n Enter Bank3 name: ";
                        getline(cin >> ws, bank3);
                        cout<<"\n Enter bank4 name: ";
                        getline(cin >> ws, bank4);
						             

                        o = b.compare(b.check1(bank1), b.check2(bank2), b.check3(bank3), b.check4(bank4));
                        if(o==1)
						 cout<<bank1<<" interest rate is cheaper than"<<bank2<<" ,"<<bank3<<" and "<<bank4<<endl;
                        else if(o==2) 
                            cout<<bank2<<" interest rate is cheaper than"<<bank1<<" ,"<<bank3<<" and "<<bank4<<endl;
                        else if(o==3)
                            cout<<bank3<<" interest rate is cheaper than"<<bank1<<" ,"<<bank2<<" and "<<bank4<<endl;
                        else if(o==4)
                            cout<<bank4<<" interest rate is cheaper than"<<bank1<<" ,"<<bank2<<" and "<<bank3<<endl;
                        else 
                            cout<<"\n Incorrect bank name - Try again!"<<endl;            
					  }
					      break;
					}		
					  
			case 6:{
					   Broker b;
					   b.printAll();
					   break;
					}	
				
			default: cout<<"\n Invalid option, enter a valid one!"<<endl;	
		}
		cout<<"\n Do you want to continue(y/n): ";
		cin>>o;
		
	}while(o=='y');
	return 0;
}
