#include<iostream>
#include<vector>
#include"Time.h"        // to calculate time and assign delivery executive
using namespace std;

vector<class Booking> vectorOfOrders;  // Push each order taken into this vector - vectorOfOrders
int ne; // no of executives
int count=0;

class Booking
{
    public:
        int customerID, bookingID, currentOrderExecutiveIndex=0;
        string restaurant, destination, orderTime, currentOrderExecutive; 
        vector<string> executiveName, pickupTime, deliveryTime;
        vector<int> deliveryChargeEarned, allowance, noOfOrders;
        
    void booking()
    {
        string invalid="Invalid customer ID entered, please try again!";
        try{
            count++;    // to keep track of no of orders done so far
            cout<<"\n Customer ID: ";
            cin>>customerID; 
            if(cin.fail())
            throw invalid;
        }
        catch(string invalid)
        {
            cout<<"\n "<<invalid<<endl;
            exit(1);
        }
        bookingID = customerID;
        cout<<"\n Restaurant: ";
        cin>>restaurant;    
        cout<<"\n Destination: ";
        cin>>destination;   
        cout<<"\n Time: ";
        cin>>orderTime;
    }

    void disp()
    {
        cout<<"\n Available Executives: "<<endl;
        cout<<"\n Executive \t Delivery Charge Earned"<<endl;
        for(int i=0;i<ne;i++)
            cout<<"\n "<<executiveName[i]<<"\t\t\t"<<deliveryChargeEarned[i]<<endl;
    }
};

class deliveryExecutive : public Booking, Time
{
    public:

    void createDeliveryExecutives()
        {
            for(int i=0;i<ne;i++)
            {
                string temp = "DE"+ to_string(i+1);
                executiveName.push_back(temp);
                deliveryChargeEarned.push_back(0);
                allowance.push_back(0);
                noOfOrders.push_back(0);
                pickupTime.push_back("0");
                deliveryTime.push_back("0");
            }
        }    

    void calcOrder()
    {int flag=0;
        
        if(count==1)    // 1st order assigned to DE1
        {
            currentOrderExecutive = "DE1";
            currentOrderExecutiveIndex = 0;
            deliveryChargeEarned[currentOrderExecutiveIndex] += 50;
            allowance[currentOrderExecutiveIndex] += 10;
            noOfOrders[currentOrderExecutiveIndex] += 1;
            pickupTime[currentOrderExecutiveIndex] = add_time(orderTime, "15"); // add pickup time of 15mins to current order time
            deliveryTime[currentOrderExecutiveIndex] = add_time(pickupTime[currentOrderExecutiveIndex], "30");
        }
        else        
        {
            int i=0;

            // orders assigned on this part only if restaurant, destination matches previous "i" orders and 
            // difference between current order and previous "i" orders time is <= 15
            do{ 
                if((restaurant == vectorOfOrders[i].restaurant) && (destination == vectorOfOrders[i].destination) && noOfOrders[vectorOfOrders[i].currentOrderExecutiveIndex] < 5 && (diff(orderTime, vectorOfOrders[i].orderTime)))  // same executive as before? then no allowance
                {
                    currentOrderExecutive = vectorOfOrders[i].currentOrderExecutive;
                    currentOrderExecutiveIndex = vectorOfOrders[i].currentOrderExecutiveIndex;
                    deliveryChargeEarned[currentOrderExecutiveIndex] += 5;
                    noOfOrders[currentOrderExecutiveIndex] += 1;
                    pickupTime[currentOrderExecutiveIndex] = vectorOfOrders[i].pickupTime[currentOrderExecutiveIndex];
                    deliveryTime[currentOrderExecutiveIndex] = vectorOfOrders[i].deliveryTime[currentOrderExecutiveIndex];
                    flag=1;          
                    break;
                }i++;
            }while(i<vectorOfOrders.size() &&flag==0 );

            // This part is executed only when above condition fails 
            // Here orders are assigned for executives based on who has earned least delivery charge so far 
            if(!flag)   
            {
                int min=deliveryChargeEarned[0];
                for(int i=ne-1;i>=0;i--)   
                {
                    if(min>deliveryChargeEarned[i])
                        min = i;
                }        
                currentOrderExecutive = executiveName[min];
                currentOrderExecutiveIndex = min;
                deliveryChargeEarned[min] += 50;
                allowance[min] += 10;
                noOfOrders[min] += 1;
                pickupTime[currentOrderExecutiveIndex] = add_time(orderTime, "15");
                deliveryTime[currentOrderExecutiveIndex] = add_time(pickupTime[currentOrderExecutiveIndex], "30");
                
            }
        }
        cout<<"\n Alloted executive: "<<currentOrderExecutive<<endl;
    }

    void dispAvailableExecutives()
    {
        cout<<"\n Delivery History~ "<<endl;
        cout<<"\n Executive name \t Delivery charge earned \t Allowance \t No of Orders \t pickup time \t delivery time"<<endl;
        for(int i=0;i<ne;i++)
        {
            cout<<"\n "<<executiveName[i]<<"\t\t\t"<<deliveryChargeEarned[i]<<"\t\t\t\t"<<allowance[i]<<"\t\t\t"<<noOfOrders[i]<<"\t\t"<<pickupTime[i]<<"\t\t"<<deliveryTime[i]<<endl;
        }

        cout<<"\n Total Earned~ "<<endl;
        cout<<"\n Executive name \t Delivery charge earned \t Allowance \t total "<<endl;
        for(int i=0;i<vectorOfOrders.size();i++)
        {
            cout<<"\n "<<executiveName[i]<<"\t\t\t"<<deliveryChargeEarned[i]<<"\t\t\t\t"<<allowance[i]<<"\t\t"<<(deliveryChargeEarned[i]+allowance[i])<<endl;
        }
        cout<<"\n Trip \t Executive \t Restaurant \t Destination \t Orders Completed \t Pickup time \t delivery time \t delivery charge"<<endl;
        for(int i=0;i<vectorOfOrders.size();i++)
        {
            int x = 1;
            if(noOfOrders[i]>=2)
                continue;
            cout<<"\n "<<x++<<"\t"<<vectorOfOrders[i].currentOrderExecutive<<"\t\t"<<vectorOfOrders[i].restaurant<<"\t\t\t"<<vectorOfOrders[i].destination<<"\t\t"<<noOfOrders[vectorOfOrders[i].currentOrderExecutiveIndex]<<"\t\t"<<pickupTime[vectorOfOrders[i].currentOrderExecutiveIndex]<<"\t\t"<<deliveryTime[vectorOfOrders[i].currentOrderExecutiveIndex]<<"\t\t"<<deliveryChargeEarned[vectorOfOrders[i].currentOrderExecutiveIndex]<<endl;  
        }
    }

    void customerDetails()
    {
        cout<<"\n Customer ID \t Restaurant \t Destination Point \t order time"<<endl;
        for(int i=0;i<vectorOfOrders.size();i++)
        {
            cout<<"\n "<<vectorOfOrders[i].customerID<<"\t\t "<<vectorOfOrders[i].restaurant<<"\t\t\t"<<vectorOfOrders[i].destination<<"\t\t"<<vectorOfOrders[i].orderTime<<endl;
        }
    }
    
};

int main()
{
    int ch;char o;int count;deliveryExecutive de;
    cout<<"\n Enter number of delivery executives: ";
    cin>>ne;
    de.createDeliveryExecutives();
    do
    {
        cout<<"\n 1.Booking"<<endl;
        cout<<"\n 2.Display Executive History"<<endl;
        cout<<"\n 3. View customer details"<<endl;      // added feature
        cout<<"\n Enter option: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                    de.booking();
                    de.calcOrder();
                    vectorOfOrders.push_back(de);
                    de.disp();
                    break;

            case 2:  de.dispAvailableExecutives();break;

            case 3: de.customerDetails(); break;

            default: cout<<"\n Incorrect option!"<<endl;
                   
        }
        cout<<"\n cont?(y/n): ";
        cin>>o;
    }while(o=='y');

    return 0;
}
