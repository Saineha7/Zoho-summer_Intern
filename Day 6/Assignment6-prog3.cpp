#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;

class AgeNotWithinRangeException : public exception
{
    public:
        string improperAge()
        {
            return "Age is not within the range 15-21";
        }
};

class NameNotValidException : public exception
{
    public:
        string invalidName()
        {
            return "Name should not contain any special characters";
        }
};

class InvalidCourseException : public exception
{
    public:
        string unknownCourse()
        {
            return "Course unavailable";
        }
};

class MoreThanOneObject : public exception
{
    public:
        string duplicateObject()
        {
            return "Student entry already exists";
        }
};

static int objectCount = 1;
class student
{
    public:
        int rollNo, age;
        string name, course;
        string list[2]={"IT","EEE"};

        student(int placeHolder, int age, string name, string course)
        {
            try 
            {
                if(objectCount>1)
                    throw MoreThanOneObject();
            }
            catch(MoreThanOneObject m)
            {
                cout<<m.duplicateObject()<<endl;
            }
            
            this->rollNo = rollNo;
            this->age = age;
            this->name = name;
            transform(course.begin(), course.end(), course.begin(), ::toupper);
            this->course = course; 
            objectCount++;
        }

        void calculateAge()
        {
            try
            {
                if(!((age>=15)&&(age<=21)))
                {
                    age=int();
                    throw AgeNotWithinRangeException();
                }
                else
                    cout<<"\n Age: "<<age<<endl;
            }
            catch(AgeNotWithinRangeException a)
            {
                cout<<a.improperAge()<<endl;
            }
        }

        void getName()
        {
            try 
            {
                if (name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != std::string::npos)
                    throw NameNotValidException();
            }
            catch(NameNotValidException n)
            {
                cout<<n.invalidName()<<endl;
            }
        }

        void checkCourse()
        {
            try
            {
                int flag=0;
                int length = sizeof(list)/sizeof(list[0]);
                for(int i=0;i<length;i++)
                {
                    if((list[i]==course))
                    {
                        flag = 1;
                        cout<<"Course: "<<course<<endl;
                        break;
                    }    
                }
                if(flag==0)
                {
                    course.clear();
                    throw InvalidCourseException();
                }
                        
            }
            catch(InvalidCourseException i)
            {
                cout<<i.unknownCourse()<<endl;
            }
        }
};

int main()
{
    int rollNo, age; string name, course;
    cout<<"\n Enter Roll.No: ";
    cin>>rollNo;
    cout<<"\n Enter Age: ";
    cin>>age;
    cout<<"\n Enter Name: ";
    cin>>name;
    cout<<"\n Enter course: ";
    cin>>course;
    cout<<"\n";
    student s(rollNo,age,name,course);
    s.calculateAge();
    s.getName();
    s.checkCourse();

    return 0;
}
