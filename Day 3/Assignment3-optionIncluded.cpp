#include<iostream>
#include<vector>
#include<memory>
using namespace std;

// use C++ 14

struct coordinates{
    int x;
    int y;
};

// Given - Write a function that will return an array with group members count and number of groups formed, so 
// have created this struct.
struct result
{
    unique_ptr<int[]> arr;
    int count;
}s;

class city
{
    
    public:
        int Nrows, Mcols, group=0, leaderGroup, leaderGroupindex;
        unique_ptr<unique_ptr<int[]>[]>     buildings, visited;
        unique_ptr<int[]>                   families, tempVisit;
    public:
        void getInput();
        void formMatrix();
        void Grouping(int i, int j, int flag);
        void findTotalGroups();
        void findLeaderGroup();
        void disp();
        void printVisitMatrix();
        void shortestDistMatrix();
        
        city()
        {
            tempVisit = 0;
            leaderGroup = 0;
        }
};

void city::getInput()
{
    cout<<"\n Enter no of rows: ";
    cin>>Nrows;
    cout<<"\n Enter no of cols: ";
    cin>>Mcols;
    formMatrix();
}

void city::formMatrix()
{
    int noOfPersons;
    buildings = make_unique< unique_ptr<int[]>[] >(Nrows);
    visited = make_unique< unique_ptr<int[]>[] >(Nrows);
    
    for(int i=0; i<Nrows; i++)
    {
        families = make_unique<int[]>(Mcols);
        tempVisit = make_unique<int[]>(Mcols);
        cout<<"\n Enter values for row "<<i+1<<": "<<endl;
        for(int j=0; j<Mcols; j++)
        {
            cin>>noOfPersons;               // get the no of persons per family
            families[j] = noOfPersons;
        }
        buildings[i] = move(families);      // move 1D array value into 2D
        visited[i] = move(tempVisit);       // visited matrix initialization
    }
}

void city::Grouping(int i, int j, int flag)
{
    if(visited[i][j] != 0)  // if visited return 
	{
		return;
	}
	else
	{
		group += buildings[i][j];
        visited[i][j] = flag;
		if(i+1 < Nrows && buildings[i+1][j] !=0) // explore downwards the neihbours of 1 entry
		{
			Grouping(i+1,j,flag); // recursively explore all the values of column and add to grpSize
		}
		// if adjacent element is 0 then we won't explore furthermore
		if(i-1 >= 0 && buildings[i-1][j] !=0) // explore upwards of an element
		{
			Grouping(i-1,j,flag);
		}
		if(j+1 < Mcols && buildings[i][j+1] !=0) // explore horizontally (RHS)
		{
			Grouping(i,j+1,flag); 
		}
		if(j-1 >= 0 && buildings[i][j-1] !=0) // explore LHS of an element
		{
			Grouping(i,j-1,flag);
		}
		return;
	}	
}

void city::findTotalGroups()
{
    s.arr = make_unique<int[]>(10);int x;int flag=0;
    for(int i=0;i<Nrows;i++)
    {
        for(int j=0;j<Mcols;j++)
        {
            if(buildings[i][j]!=0)          // if not an empty building
            {
                Grouping(i,j,s.count+1);    // then group families 
                if(group!=0)                // if group formed 
                {
                    x = ++s.count;          // increase the group count by 1
                    s.arr[x] = group;       // push the members count in each group 
                }
                group = 0; 
            }
        }
    }
    
    cout<<"Output groups: ";
    for(int i=1;i<=s.count;i++)
    {
        cout<<s.arr[i]<<" ";
    }
    cout<<"\n";
    return;
}

void city::findLeaderGroup()
{
    for(int i=1;i<=s.count;i++)
    {
        if(s.arr[i]>leaderGroup){    // check the array which has the members count in each group
            leaderGroup=s.arr[i];
            leaderGroupindex = i;}
    }
    cout<<"\n Leader group: "<<leaderGroup<<endl;
    cout<<"\n Leader group index: "<<leaderGroupindex<<endl;
}

void city::disp()
{
    cout<<"\n Entered matrix is: "<<endl;
    for(int i=0;i<Nrows;i++)
    {
        for(int j=0;j<Mcols;j++)
        {
            cout<<buildings[i][j]<<" ";
        }
        cout<<endl;
    }
}

void city::printVisitMatrix()
{
    cout<<"\n Visit matrix: "<<endl;
    for(int i=0;i<Nrows;i++)
    {
        for(int j=0;j<Mcols;j++)
        {
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
}

void city::shortestDistMatrix()
{
    vector<coordinates> coord;
    vector<vector<coordinates>> groupCoordinates(10);
    for(int i=0;i<Nrows;i++)
    {
        for(int j=0;j<Mcols;j++)
        {
            if (visited[i][j] == leaderGroupindex)    
            {
                coordinates c;                      // c has leader group coordinates
                c.x = i;
                c.y = j;
                coord.push_back(c);
            }
            
            else if(visited[i][j]!=0 && visited[i][j]!=leaderGroupindex)
            {
                coordinates g;                      // g has other group coordinates
                int temp=visited[i][j];
                g.x = i;
                g.y = j;
                groupCoordinates[temp].push_back(g);
            }
        }
    
    }

    int size = coord.size();int z;int i;

    vector<int> dist; int min=0;
    cout<<"\n Path: ";

   for(int i=1;i<=s.count;i++)      // s.count = no of groups 
    {
        if(i!=leaderGroupindex){
        int distance = 999;
        for(int j=0;j<groupCoordinates[i].size();j++)
        {
            
            for (int k = 0; k < size; k++)  // k is used to access leader group coordinates
            {
                int d = (abs((groupCoordinates[i][j].x)-coord[k].x) + abs((groupCoordinates[i][j].y)-coord[k].y)-1);
                if (d < distance)
                    distance = d;
            }
                    
        }
        dist.push_back(distance);
        }
    }
    for(int i=0;i<dist.size();i++)
    cout<<dist[i]<< " ";  
}

int main()
{
    city c;
    c.getInput();
    c.disp();
    c.findTotalGroups();
    c.findLeaderGroup();
    c.printVisitMatrix();
    c.shortestDistMatrix();
    return 0;
}
