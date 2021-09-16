#include<iostream>
using namespace std;
int size=0;
struct node{
	int data;
	node *next;
};
class linked_list{
	public:
		node *head,*tail;
		linked_list()
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
			else 
			{
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
			cout<<"\n";
		}
		void delete_at_first()
		{
			node *t=head;
			head=head->next;
			t=NULL;
		}
		void delete_at_end()
		{
			node *t=head;
			while(t->next!=tail)
			{
				t=t->next;
			}
			tail=t;
			tail->next=NULL;
		}
		void delete_middle(int data)
		{
			node *t=head,*prev=head,*nex;
			while(t->data!=data)
			{
				t=t->next;
			}
			while(prev->next!=t)
			{
				prev=prev->next;
			}
			nex=t->next;
			prev->next=NULL;
			prev->next=nex;
		}
		node *search(int data)
		{
			int cnt=0;
			node *t=head;
			while(t->data!=data)
			{
				t=t->next;
				if(t->data==data)
				{
					cout<<"Data Found : "<<t->data<<"\nAt Position : "<<cnt+1<<"\n";
					return t;
				}
				cnt++;
			}
		}
};
class hashing{
	public:
		linked_list *hashtable;
		hashing()
		{
			hashtable=new linked_list[size];
		}
		void insertion(int data,int index)
		{
			hashtable[index].insert(data);
		}
		void display()
		{
			for(int i=0;i<size;i++)
			{
				cout<<"Index "<<i+1<<" \n";
				hashtable[i].display();
			}
			cout<<"\n";
		}
		void searching(int data)
		{
			int index=data%size;
			cout<<"At Index : "<<index+1<<"\n";
			hashtable[index].search(data);
		}
		void delete_data(int data)
		{
			node *temp;
			int index=data%size;
			temp=hashtable[index].search(data);
			if(temp==hashtable[index].head)
			{
				hashtable[index].delete_at_first();
			}
			if(temp==hashtable[index].tail)
			{
				hashtable[index].delete_at_end();
			}
			if(temp!=hashtable[index].head && temp==hashtable[index].tail)
			{
				hashtable[index].delete_middle(data);
			}
		}
};
int main()
{
	int arr[]={50,700,76,85,92,73,101};
	size=sizeof(arr)/sizeof(int);
	hashing h;
	for(int i=0;i<size;i++)
	{
		h.insertion(arr[i],arr[i]%size);
	}
	h.display();
	h.searching(85);
	h.delete_data(85);
	h.display();
}
