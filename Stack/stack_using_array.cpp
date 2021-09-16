#include<iostream>
#define size 10
using namespace std;
class stacks{
	public:
		int *stack,top;
		stacks()
		{
			top=-1;
			stack=new int[size];
			for(int i=0;i<size;i++)
			{
				stack[i]=0;
			}
		}
		int push(int data)
		{
			if(top==size)
			{
				cout<<"Stack Is Full \n ";
				return -1;
			}
			top++;
			stack[top]=data;
		}
		int pop()
		{
			int ret=0;
			ret=stack[top];
			top--;
			return ret;
		}
		void display()
		{
			for(int i=top;i>=0;i--)
			{
				cout<<stack[i]<<" ";
			}
			cout<<"\n";
		}
		bool isempty()
		{
			if(top==-1)
			{
				return true;
			}
			else {
				return false;
			}
		}
		bool isfull()
		{
			if(top==size-1)
			{
				return true;
			}
			else {
				return false;
			}
		}
};
int main()
{
	stacks s1;
	s1.push(10);
	s1.push(18);
	s1.push(2);
	s1.push(16);
	s1.push(9);
	s1.display();
	s1.pop();
	s1.push(34);
	s1.push(22);
	s1.push(26);
	s1.push(84);
	s1.push(21);
	s1.push(66);
	s1.display();
	bool cond=s1.isempty();
	if(cond==true)
	{
		cout<<"stack is empty\n";
	}
	else{
		cout<<"Stack is not empty\n";
	}
	cond=s1.isfull();
	if(cond==true)
	{
		cout<<"stack is full\n";
	}
	else{
		cout<<"Stack is not full\n";
	}
}
