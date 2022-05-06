#include<iostream>
#include<memory>
using namespace std;

struct result
{
    unique_ptr<int[]> arr;
    int count;
}s;

class city
{
    
    public:
        int Nrows, Mcols, group=0, leaderGroup;
        unique_ptr<unique_ptr<int[]>[]>     buildings, visited;
        unique_ptr<int[]>                   families, tempVisit;
    public:
        void getInput();
        void formMatrix();
        void Grouping(int i, int j);
        void findTotalGroups();
        void findLeaderGroup();
        void disp();
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
            cin>>noOfPersons;
            families[j] = noOfPersons;
        }
        buildings[i] = move(families);
        visited[i] = move(tempVisit);
    }
}

void city::Grouping(int i, int j)
{
    if(visited[i][j] == 1)  // if visited return 
	{
		return;
	}
	else
	{
		group += buildings[i][j];
		if(i+1 < Nrows && buildings[i+1][j] !=0) // explore downwards the neihbours of 1 entry
		{
			visited[i][j] = 1;
			Grouping(i+1,j); // recursively explore all the values of column and add to grpSize
		}
		// if adjacent element is 0 then we won't explore furthermore
		if(i-1 >= 0 && buildings[i-1][j] !=0) // explore upwards of an element
		{
			visited[i][j] = 1;
			Grouping(i-1,j);
		}
		if(j+1 < Mcols && buildings[i][j+1] !=0) // explore horizontally 
		{
			visited[i][j] = 1;
			Grouping(i,j+1); 
		}
		if(j-1 >= 0 && buildings[i][j-1] !=0) // explore LHS of an element
		{
			visited[i][j] = 1;
			Grouping(i,j-1);
		}
		return;
	}	
}

void city::findTotalGroups()
{
    s.arr = make_unique<int[]>(10);int x;
    for(int i=0;i<Nrows;i++)
    {
        for(int j=0;j<Mcols;j++)
        {
            if(buildings[i][j]!=0)
            {
                Grouping(i,j);
                if(group!=0)
                {
                    x = ++s.count;
                    s.arr[x] = group; 
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
        if(s.arr[i]>leaderGroup)
            leaderGroup=s.arr[i];
    }
    cout<<"\n Leader group: "<<leaderGroup<<endl;
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

int main()
{
    city c;
    c.getInput();
    c.disp();
    c.findTotalGroups();
    c.findLeaderGroup();
   
    return 0;
}
