#include<iostream>
using namespace std;
int cnt;
struct node{
	int data;
	node *next;
};
class Linked_List{
	public:
		node *head,*tail;
		Linked_List()
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
				temp=NULL;
			}
			else {
				tail->next=temp;
				tail=temp;
				temp=NULL;
			}
		}
		void display()
		{
			node *t=head;
			while(t!=NULL)
			{
				cout<<t->data<<" ";
				t=t->next;
			}
		}
		node *search(int data)
		{
			node *t=head;
			while(t!=NULL)
			{
				if(t->data==data)
				{
					return t;
				}
				t=t->next;
			}
		}
		void delete_at_start()
		{
			node *t=head;
			head=head->next;
			t=NULL;
		}
		void delete_at_end()
		{
			node *t=head,*prev=head;
			while(t->next!=NULL)
			{
				t=t->next;
			}
			while(prev->next!=t)
			{
				prev=prev->next;
			}
			cout<<"Current : "<<t->data<<"  Previous : "<<prev->data<<" \n";
			tail=prev;
			tail->next=NULL;
		}
		void delete_at_middle(int data)
		{
			node *t,*prev,*nex;
			t=head;
			prev=head;
			nex=head;
			while(t->data!=data)
			{
				t=t->next;
			}
			while(prev->next!=t)
			{
				prev=prev->next;
			}
			nex=t->next;
			cout<<"Previous : "<<prev->data<<"  current : "<<t->data<<" next : "<<nex->data<<" \n";
			prev->next=NULL;
			prev->next=nex;
		}
		void insert_any_pos(int data,int pos)
		{
			node *temp=new node;
			temp->data=data;
			temp->next=NULL;
			node *t=head,*prev=head;
			for(int i=0;i<pos;i++)
			{
				t=t->next;
			}
			cout<<"At 3rd position : "<<t->data<<"\n";
			while(prev->next!=t)
			{
				prev=prev->next;
			}
			prev->next=temp;
			temp->next=t;
		}
		bool sum_of_2_adjacent_nodes()
		{
			int sum=0;
			node *t=head,*nex,*nexs;
			while(t->next!=NULL)
			{
				nex=t->next;
				nexs=nex->next;
				sum=t->data+nex->data;
				if(sum==nexs->data)
				{
					return true;
				}
				t=t->next;
			}
			return false;
		}
};
int main()
{
	int a;
	Linked_List ll;
	for(int i=0;i<5;i++)
	{
		ll.insert(i*2);
	}
	ll.display();
	cout<<"\nEnter Data To Display : ";
	cin>>a;
	node *t=ll.search(a);
	cout<<"\nSearched Data : "<<t->data<<"\n";
	cout<<"Enter Data To Delete : ";
	cin>>a;
	ll.insert_any_pos(19,3);
	cout<<endl;
	ll.display();
	bool c=ll.sum_of_2_adjacent_nodes();
	if(c==true )
	{
		cout<<"Found\n";
	}
	else if(c==false){
		cout<<"not found\n";
	}
}
