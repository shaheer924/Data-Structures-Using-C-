#include<iostream>
using namespace std;
struct node{
	int data;
	node *prev;
};
class stack{
public:
	node *top;
	stack()
	{
		top=NULL;
	}
	void push(int data)
	{
		node *temp=new node;
		temp->data=data;
		temp->prev=NULL;
		if(top==NULL)
		{
			top=temp;
		}
		else
		{
			temp->prev=top;
			top=temp;
		}
	}
	node *pop()
	{
		node *t=top;
		top=top->prev;
		return t;
	}
	void display()
	{
		node *t=top;
		while(t!=NULL)
		{
			cout<<t->data<<" ";
			t=t->prev;
		}
		cout<<"\n";
	}
};
int main()
{
	stack s1;
	s1.push(10);
	s1.push(18);
	s1.push(2);
	s1.push(16);
	s1.push(9);
	s1.display();
	s1.pop();
	s1.display();
}

