#include<string>
#include<cstdlib>
using namespace std;

class Time 
{
    public:
     int hours=0, mins=0, temp,hours1=0, mins1=0, difference, totalMins1, totalMins2, hours2=0, mins2=0, pos1, pos2, min;
    string totTime,pos,temp1,temp2;

     string add_time(string orderTime, string no)    // string no will either be 15 if its for pickup and 30 for delivery 
    {
        int m=0;
        pos1 = orderTime.find(":");
        hours = stoi(orderTime.substr(0,pos1));     // store the hours part of the input
        m = stoi(orderTime.substr(pos1+1,pos1+2));  // store the mins part of the input
        temp1 = orderTime.substr(orderTime.size()-2,orderTime.size()-1);     // store the AM/PM part of the input
        if((temp1=="PM"&&hours!=12)||(temp1=="AM"&&hours==12))
            hours += 12;
        else 
            hours = hours;
        mins = m + stoi(no);            // Add the pickup or delivery time 
        adjust_time();
        append();
        string str = convert();
        return str;
    }

    int diff(string orderTime, string prevOrderTime)
    {
        int h=0, m=0;
        pos1 = orderTime.find(":");
        h = stoi(orderTime.substr(0,pos1));
        m = stoi(orderTime.substr(pos1+1,pos1+2));
        temp1 = orderTime.substr(orderTime.size()-2,orderTime.size()-1);
        
        pos2 = prevOrderTime.find(":");
        hours2 = stoi(prevOrderTime.substr(0,pos2));
        mins2 = stoi(prevOrderTime.substr(pos2+1,pos2+2));
        temp2 = prevOrderTime.substr(prevOrderTime.size()-2,prevOrderTime.size()-1);
        
        if((temp1 == temp2) && (temp1 == "AM"||"PM"))
        {
            totalMins1 = (h*60+m);
            totalMins2 = (hours2*60+mins2);
            difference = abs(totalMins1 - totalMins2);
            if(difference<=15) return 1;               // works for both AM and PM i.e 11:50AM and 12:05 PM will also be accepted
            else return 0;
        }
            
        else if(temp1 != temp2 && h!=hours2)
        {
            totalMins1 = (h*60+m);
            totalMins2 = (hours2*60+mins2);
            difference = abs(totalMins1 - totalMins2);
            if(difference<=15) return 1;               // works for both AM and PM i.e 11:50AM and 12:05 PM will also be accepted
            else return 0;
        }
        else return 0;
        
    }

    void adjust_time()
    {
        while(mins>=60)
        {
            mins -= 60;
            hours += 1;
        }
        if(hours==24)
            hours = 00;
    }

    void append()
    {
        if(mins<10)
        totTime = to_string(hours)+"0"+to_string(mins);
        else 
        totTime = to_string(hours)+to_string(mins);
    }

    string convert()
    {    
        string str, val;
        hours = stoi(totTime)/100;
        mins = stoi(totTime)%100;    
        if(hours==0&&hours!=12){
            hours=12; 
            val = "AM";
            }
        else if(hours==12&&hours!=0){
            hours=12; 
            val = "PM";
            }
        else if(hours<12&&hours!=0){
            hours=hours;
            mins=mins; 
            val = "AM";
            }
        else if(hours>12&&hours!=0)
            { 
            hours = hours-12; 
            mins = mins; 
            val = "PM";
            }
            (mins < 10) ? str = to_string(hours)+":0"+to_string(mins)+val : str = to_string(hours)+":"+to_string(mins)+val;
            return str;
    }

    int check()
    {
        if(hours==0 && mins <=15)
            return 1;
        else if(hours==0 && mins <=30)
            return 1;
        else if(hours)
            return 0;
    }

};
