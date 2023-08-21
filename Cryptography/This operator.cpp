//This operator
#include<iostream>
#include<string>
using namespace std;
class person
{
	int number;
	int age;
	public:
		void setdata(int number,int age)
		{
			this->number=number;
			this->age=age;
		}
		void display()
		{
			cout<<"number="<<number<<endl;
			cout<<"age="<<age<<endl;
		}
};
int main()
{
	person p;
	p.setdata(12,45);
	p.display();
}
