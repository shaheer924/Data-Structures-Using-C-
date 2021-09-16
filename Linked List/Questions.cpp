#include<iostream>
using namespace std;
struct node{
	string name;
	node *next;
};
class flight_linked_list{
	public:
		node *head,*tail;
		flight_linked_list()
		{
			head=NULL;
			tail=NULL;
		}
		void insert_reservation(string name)
		{
			node *temp=new node;
			temp->name=name;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
				temp=NULL;
			}
			else {
				tail->next=temp;
				tail=tail->next;
				temp=NULL;
			}
		}
		bool search_check_reservation(string name)
		{
			node *t=head;
			while(t->name!=name)
			{
				if(t->name==name)
				{
					cout<<"true\n";
					return true;
				}
				t=t->next;
			}
			cout<<"false\n";
			return false;
		}
		void delete_cancel_reservation(string name)
		{
			node *t=head,*nex,*pre=head;
			if(head->name==name)
			{
				head=head->next;
				t=NULL;
			}
			else if(tail->name==name)
			{
				while(pre->next!=tail)
				{
					pre=pre->next;
				}
				tail=pre;
				tail->next=NULL;
			}
			else if(head->name!=name && tail->name!=name)
			{
				pre=head;
				while(t->name!=name)
				{
					t=t->next;
				}
				while(pre->next!=t)
				{
					pre=pre->next;
				}
				nex=t->next;
				
				pre->next=nex;
				t=NULL;
			}
		}
		void display()
		{
			node *t=head;
			while(t!=NULL)
			{
				cout<<t->name<<" ";
				t=t->next;
			}
			cout<<"\n";
		}
};
int main()
{
	flight_linked_list fll;
	fll.insert_reservation("shaheer");
	fll.insert_reservation("anas");
	fll.insert_reservation("saad");
	fll.insert_reservation("ahmed");
	fll.display();
	fll.delete_cancel_reservation("anas");
	fll.display();
	fll.search_check_reservation("shaheer");
	fll.search_check_reservation("anas");
}
