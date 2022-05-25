#include<iostream>
#include<cmath>
using namespace std;
 
class Rectangle
{
	public:
		int *left, *top, *width, *height, *area=NULL;
 
	public:
		Rectangle()
		{
			left = new int(0);
			top = new int(0);
			width = new int(0);
			height = new int(0);
		}
 
		Rectangle(int width, int height)
		{
			left = new int(0);
			top = new int(0);
			this->width = new int(width);
			this->height = new int(height);
		}	
 
		Rectangle(int left, int top, int width, int height)
		{
			this->left = new int(left);
			this->top = new int(top);
			this->width = new int(width);
			this->height = new int(height);
		}
 
		Rectangle(float left, float top, float width, float height)
		{
			this->left = new int(round(left));
			this->top = new int(round(top));
			this->width = new int(round(width));
			this->height = new int(round(height));
		}
 
		Rectangle(Rectangle &a)
		{
			left = new int(*a.left);
			top = new int(*a.top);
			width = new int(*a.width);
			height = new int(*a.height);
			a.area = new int(*width * *height);
			area = new int(*a.area);
		}
 
		void print()
		{
			cout<<"\n Left: "<<"\t Top: "<<"\t Width: "<<" Height: "<<endl;
			cout<<"\n "<<*left<<"\t "<<*top<<"\t "<<*width<<"\t "<<*height<<endl;
			if(area)cout<<"\n Area: "<<*area<<endl;
		}
 
		~Rectangle()
		{
			cout<<"\n Destructor called"<<endl;
			delete(left);
			delete(top);
			delete(width);
			delete(height);
			delete(area);
		}
};
 
int main()
{	
 
	Rectangle r1;
	r1.print();
 
	Rectangle r2(1,2);
	r2.print();
 
	Rectangle r3(1,2,3,4);
	r3.print();
 
	Rectangle r4(1.2f,2.3f,3.4f,4.5f);
	r4.print();
 
	Rectangle r5(r4);
	r5.print();
	return 0;
}
