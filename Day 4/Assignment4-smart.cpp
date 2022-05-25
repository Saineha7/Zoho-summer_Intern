#include<iostream>
#include<cmath>
#include<memory>
using namespace std;

class Rectangle
{
	public:
		unique_ptr<int> left, top, width, height, area;

	public:
		Rectangle()
		{
			left = make_unique<int>(0);
			top = make_unique<int>(0);
			width = make_unique<int>(0);
			height = make_unique<int>(0);
		}
		
		Rectangle(int width, int height)
		{
			left = make_unique<int>(0);
			top = make_unique<int>(0);
			this->width = make_unique<int>(width);
			this->height = make_unique<int>(height);
		}	
		
		Rectangle(int left, int top, int width, int height)
		{
			this->left = make_unique<int>(left);
			this->top = make_unique<int>(top);
			this->width = make_unique<int>(width);
			this->height = make_unique<int>(height);
		}
		
		Rectangle(float left, float top, float width, float height)
		{
			this->left = make_unique<int>(round(left));
			this->top = make_unique<int>(round(top));
			this->width = make_unique<int>(round(width));
			this->height = make_unique<int>(round(height));
		}
		
		Rectangle(Rectangle &a)
		{
			left = make_unique<int>(*a.left);
			top = make_unique<int>(*a.top);
			width = make_unique<int>(*a.width);
			height = make_unique<int>(*a.height);
			a.area = make_unique<int>(*width * *height);
			area = make_unique<int>(*a.area);
		}
		
		void print()
		{
			cout<<"\n Left: "<<"\t Top: "<<"\t Width: "<<" Height: "<<endl;
			cout<<"\n "<<*left<<"\t "<<*top<<"\t "<<*width<<"\t "<<*height<<endl;
			if(area) cout<<"\n Area: "<<*area<<endl;
		}
		
		~Rectangle()
		{
			cout<<"\n Destructor called"<<endl;
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
