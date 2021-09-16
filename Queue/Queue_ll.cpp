#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class queue{
public:	
	node *front,*rear;
	queue()
	{
		front=NULL;
		rear=NULL;
	}
	void enqueue(int data)
	{
		node *temp=new node;
		temp->data=data;
		temp->next=NULL;
		if(front==NULL)
		{
			front=temp;
			rear=temp;
			temp=NULL;
		}
		else{
			rear->next=temp;
			rear=temp;
			temp=NULL;
		}
	}
	node *dequeue()
	{
		node *t=front;
		front=front->next;
		cout<<t->data<<" ";
		t=NULL;
	}
	void display()
	{
		node *t=front;
		while(t!=NULL)
		{
			cout<<t->data<<" ";
			t=t->next;
		}
		cout<<"\n";
	}
};
int main()
{
	queue s1;
	s1.enqueue(10);
	s1.enqueue(18);
	s1.enqueue(2);
	s1.enqueue(16);
	s1.enqueue(9);
	s1.display();
	s1.dequeue();
	cout<<"\n";
	s1.display();
}
