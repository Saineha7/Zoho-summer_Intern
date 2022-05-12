#include<iostream>
using namespace std;

class vehicle
{
	protected:
		string vehicleType, brand, model, color;
		int mileage, price;	
		virtual void getNoOfWheels() = 0;
	
	// initializing values using constructor 	
	vehicle(string vehicleType, string brand, string model, string color, int mileage, int price)
	{
		this->vehicleType = vehicleType;
		this->brand = brand;
		this->model = model;
		this->color = color;
		this->mileage = mileage;
		this->price = price;
	}	
	friend ostream& operator<<(ostream& os,vehicle &v);
	friend bool operator<(vehicle &v1, vehicle &v2);
};

// class car derived from base class vehicle
class car: public vehicle 
{
	private:
		int noOfPersons;
		string carType;
	public:
		virtual void getNoOfWheels() {cout<<"4 wheels";}
	
		// Initialize car object with respective values
		car(string vehicleType, string brand, string model, string color, int mileage, int price, int noOfPersons, string carType):vehicle(vehicleType, brand, model, color, mileage, price)
		{
			this->noOfPersons = noOfPersons;
			this->carType = carType;
		}
};

// class bike derived from base class vehicle
class bike: public vehicle
{
	private:
		int weight;
		string bikeType;
		public:
		virtual void getNoOfWheels() {cout<<"2 wheels";}
		
		// Initialize bike object with respective values
		bike(string vehicleType, string brand, string model, string color, int mileage, int price, int weight, string bikeType):vehicle(vehicleType, brand, model, color, mileage, price)
		{
			this->weight = weight;
			this->bikeType = bikeType;
		}	
};

// definition for overloading output insertion operator (<<)
ostream& operator<<(ostream& os, vehicle &v)
{
	os <<"Brand: "<<v.brand<<"\n"<<"Model: "<< v.model<<"\n"<< "Type: "<< v.vehicleType<<"\n"<< "Color: "<<v.color<<"\n"<<"Price: "<<v.price<<endl;
	return os;
}

//definition for overloading less than operator(<)
 bool operator<(vehicle &v1, vehicle &v2)
{
	return v1.price<v2.price;
}

int main()
{
	
	int ch; char o;
	do
	{
		cout<<"\n 1. compare 2 bikes"<<endl;
		cout<<"\n 2. compare 2 cars"<<endl;
		cout<<"\n 3. compare 1 car and 1 bike"<<endl;
		cout<<"\n Enter option: ";
		cin>>ch;
		cout<<"\n";
		
		switch(ch)
		{
			case 1: {
			        bike b1("petrol", "tvs", "tvs-50", "green", 20,100000,100,"scooter");
					cout<<b1;
					b1.getNoOfWheels(); cout<<"\n\n";
					bike b2("petrol", "ktm", "duke-390", "orange", 20,500000,100,"motorBike");
					cout<<b2;
					b2.getNoOfWheels(); cout<<"\n\n";
					int x = b1 < b2; if(x) cout<<"bike1 is cheaper!"; else cout<<"Bike2 is cheaper!"<<endl;
					break;
			}
					
			case 2: {car c1("petrol","hyundai","i10","black",12,120000,5,"suv");
					cout<<c1;
					c1.getNoOfWheels(); cout<<"\n\n";
					car c2("diesel", "Honda", "amaze", "blue", 18,800000,5,"sedan");
					cout<<c2;
					c2.getNoOfWheels(); cout<<"\n\n";
					int x = c1 < c2; if(x) cout<<"Car1 is cheaper!"; else cout<<"Car2 is cheaper!"<<endl;
					break;	}
					
			case 3:	{car c("petrol","hyundai","i10","black",12,120000,2,"suv");
					cout<<c;
					c.getNoOfWheels(); cout<<"\n\n";
					bike b("petrol", "tvs", "tvs-50", "green", 20,100000,100,"scooter");
					cout<<b;
					b.getNoOfWheels(); cout<<"\n\n";
					int x = c < b; if(x) cout<<"Car is cheaper!"; else cout<<"Bike is cheaper!"<<endl;
					break;	}
				
			default: cout<<"\n Invalid option, enter a valid one!"<<endl;	
		}
		cout<<"\n";
		cout<<"\n Do you want to continue(y/n): ";	
		cin>>o;
	}while(o=='y');
	return 0;
}
