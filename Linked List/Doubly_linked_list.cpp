#include<iostream>
using namespace std;
struct node{
	int data;
	node *next,*prev;
};
class Doubly_Linked_list{
	public:
		node *head,*tail;
		Doubly_Linked_list()
		{
			head=NULL;
			tail=NULL;
		}
		void insert(int data)
		{
			node *temp=new node;
			temp->data=data;
			temp->next=NULL;
			temp->prev=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else {
				tail->next=temp;
				temp->prev=tail;
				tail=temp;
			}
		}
		void insert_at_start(int data)
		{
			node *temp=new node;
			temp->data=data;
			temp->next=NULL;
			temp->prev=NULL;
			temp->next=head;
			head->prev=temp;
			head=head->prev;
		}
		void insert_at_any_position(int data,int pos)
		{
			node *pre=head;
			node *nex=head;
			node *temp=new node;
			temp->data=data;
			temp->next=NULL;
			temp->prev=NULL;
			for(int i=0;i<pos-1;i++)
			{
				nex=nex->next;
			}
			pre=nex->prev;
			pre->next=temp;
			temp->prev=pre;
			nex->prev=temp;
			temp->next=nex;
			temp=NULL;
		}
		void delete_at_start()
		{
			node *t=head;
			head=head->next;
			t=NULL;
		}
		void delete_at_end()
		{
			node *t=tail;
			tail=tail->prev;
			tail->next=NULL;
		}
		void delete_at_any_pos(int pos)
		{
			node *t=head,*pre=head,*nex=head;
			for(int i=0;i<pos-1;i++)
			{
				t=t->next;
			}
			pre=t->prev;
			nex=t->next;
			pre->next=nex;
			nex->prev=pre;
			t=NULL;
		}
		void traverse()
		{
			node *t=head;
			while(t!=NULL)
			{
				cout<<t->data<<" ";
				t=t->next;
			}
			cout<<"\n";
		}
		void swaping_Extreme_nodes()
		{
			node *t1=head,*t2=tail;
			head=head->next;
			tail=tail->prev;
			tail->next=t1;
			t1->prev=tail;
			t2->next=head;
			head->prev=t2;
			head=head->prev;
			tail=tail->next;
			tail->next=NULL;
			head->prev=NULL;
		}
		void swapping_from_start(int data)
		{
			node *t=head,*nex,*pre;
			while(t->data!=data)
			{
				t=t->next;
			}
			nex=t->next;
			pre=t->prev;
			
			pre->next=nex;
			nex->prev=pre;
			
			t->next=head;
			head->prev=t;
			head=t;
			head->prev=NULL;
		}
		void swapping_from_end(int data)
		{
			node *t=tail,*nex,*pre;
			while(t->data!=data)
			{
				t=t->prev;
			}
			pre=t->prev;
			nex=t->next;
			
			pre->next=nex;
			nex->prev=pre;
			
			tail->next=t;
			t->prev=tail;
			tail=tail->next;
			tail->next=NULL;
		}
};
int main()
{
	Doubly_Linked_list dll;
	for(int i=0;i<5;i++)
	{
		dll.insert(2*i);
	}
	dll.traverse();
	cout<<"Inserting at start \n";
	dll.insert_at_start(34);
	dll.traverse();
	cout<<"inserting at any position\n";
	dll.insert_at_any_position(25,3);
	dll.traverse();
	cout<<"delete at start\n";
	dll.delete_at_start();
	dll.traverse();
	cout<<"Delete at end\n";
	dll.delete_at_end();
	dll.traverse();
	cout<<"delete at pos 3\n";
	dll.delete_at_any_pos(3);
	dll.traverse();
	cout<<"Swapping Extreme Nodes\n";
	dll.swaping_Extreme_nodes();
	dll.traverse();
	cout<<"Swapping from start\n";
	dll.swapping_from_start(25);
	dll.traverse();
	cout<<"Swapping from end\n";
	dll.swapping_from_end(6);
	dll.traverse();
}
