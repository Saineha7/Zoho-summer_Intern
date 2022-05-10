#include<iostream>
#include<cstring>
#include "Assignment5-file1.cpp"

namespace m = maths;
class call
{	
	public:
		int op;
		void calculateTemperature()
		{
			float celcius;
			std::cout<<"\n Enter temperature in celcius: ";
			std::cin>>celcius;
			std::cout<<"\n Farenheit: "<<m::temperature::celciusToFarenheit(celcius);
		}

		int option()
		{
			std::cout<<"\n 1. Temperature"<<std::endl;
			std::cout<<"\n 2. Calculator"<<std::endl;
			std::cout<<"\n Enter option: ";
			std::cin>>op; 
			return op;
		}
};

int main()
{
	call c; int ch,x,y; char o;
	m::result s;
	int Output = c.option();

	if(Output==1) c.calculateTemperature();
	else if(Output==2)
	{
		do
		{
			std::cout<<"\n 1. Addition"<<std::endl;
			std::cout<<"\n 2. Subtraction"<<std::endl;
			std::cout<<"\n 3. Multiplication"<<std::endl;
			std::cout<<"\n 4. Division"<<std::endl;
			std::cout<<"\n Enter choice: ";
			std::cin>>ch;
			std::cout<<"\n";
			
			std::cout<<"\n Enter 2 numbers: ";
			std::cin>>x>>y;
			switch(ch)
			{
			case 1: std::cout<<"\n Sum: "<<s.sum(x,y)<<std::endl; break;
						
			case 2: std::cout<<"\n Difference: "<<s.difference(x,y)<<std::endl; break;    
			
			case 3: std::cout<<"\n Multiplication: "<<s.multiplication(x,y)<<std::endl; break;
			
			case 4: std::cout<<"\n Division: "<<s.division(x,y)<<std::endl; break;

			default: std::cout<<"\n Enter correct option";
						
			}
			std::cout<<"\n Do you want to continue(Y/N): ";
			std::cin>>o;
		}while(o=='y');
	}
	else std::cout<<"\n Invalid option!";
	return 0;
}
