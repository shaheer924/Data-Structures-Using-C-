#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class circular_linked_list{
	public:
		node *head,*tail;
		circular_linked_list()
		{
			head=NULL;
			tail=NULL;
		}
		void insert(int data)
		{
			node *temp=new node;
			temp->data=data;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				tail->next=temp;
			}
			else {
				tail->next=temp;
				tail=temp;
				tail->next=head;
				temp=NULL;
			}
		}
	void traverse()
	{
		node *t=head;
		while(t->data!=tail->data)
		{
			cout<<t->data<<" ";
			t=t->next;
		}
		cout<<"\n"<<t->data;
	}
};
int main()
{
	circular_linked_list cll;
	for(int i=0;i<5;i++)
	{
		cll.insert(2*i);
	}
	cll.traverse();
}
