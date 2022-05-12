#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Bank
{
	protected:
		string name, estDate, bankType;
		float intRate;
	public:
		string getName();
		string getEstablishedDate();
		string BankType();
		void getInfo();
		friend Bank operator<(Bank &b1, Bank &b2);
};

string Bank::getName()
{
	string str = "Enter bank name: ";
	return str;
}

string Bank::getEstablishedDate()
{
	string str = "Enter Bank established date: ";
	return str;
}

string Bank::BankType()
{
	string str = "Enter bank type: ";
	return str;
}

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
	
};

Bank operator<(Bank &b1, Bank &b2)	
{
	if(b1.intRate < b2.intRate)
	{
		bname = b1.name;
		return b1;
	}	
	else
	{
		bname = b2.name;
		return b2;	
	}
}

int main()
{
	int ch;	char o;
	do
	{
		system("clear");
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
					  int n;
					  Bank t1, t2, t3; HDFC h; SBI s; ICICI i; IndianBank ib; 
					  cout<<"\n Enter no of banks to compare: ";
					  cin>>n; 
					  if(n==2)
					  {
					  	t1 = h < s;
					  	cout<<"\n Between HDFC and SBI "<<bname<<" interest rate is cheaper"<<endl;
					  }
					  else if(n==3)
					  {
						t1 = h < s;
						t2 = i < t1;
						cout<<"\n Among HDFC, SBI and ICICI "<<bname<<" interest rate is cheaper"<<endl;
					  }
					  else
					  {
					  	t1 = h < s;
					  	t2 = i < t1;
					  	t3 = ib < t2;
						cout<<"\n Among HDFC, SBI, ICICI and Indian Bank"<<bname<<" interest rate is cheaper"<<endl;   
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
