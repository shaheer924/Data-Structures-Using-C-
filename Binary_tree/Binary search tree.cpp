#include<iostream>
#include<windows.h>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
class bst{
	public:
		node *head=NULL,*root;
		bst()
		{
			root=NULL;
			head==NULL;
		}
		node *insert(int data,node *head)
		{	
			if(head==NULL)
			{
				head=new node;
				head->data=data;
				head->left=NULL;
				head->right=NULL;		
			}
			else if(data < head->data)
			{
				head->left=insert(data,head->left);
			}
			else if(data > head->data)
			{
				head->right=insert(data,head->right);
			}
		}
		void preorder(node *head)
		{
			if(head!=NULL)
			{
				preorder(head->left);
				cout<<head->data<<" ";				
				preorder(head->right);
			}
		}
		node *search(int data,node *head)
		{
			if(head==NULL)
			{
				return NULL;
			}
			if(data < head->data)
			{
				cout<<"\n"<<"at left : "<<head->data<<"\n";
				search(data,head->left);
			}
			else if(data > head->data)
			{
				cout<<"at right : "<<head->data<<"\n";
				search(data,head->right);
			}
			return head;
		}
		node *minimum(node *head)
		{
			if(head==NULL)
			{
				return NULL;
			}
			node *t=head;
			while(t->left!=NULL)
			{
				t=t->left;
			}
			return t;
		}
		node *maximum(node *head)
		{
			node *t=head;
			if(head==NULL)
			{
				return NULL;
			}
			while(t->right!=NULL)
			{
				t=t->right;
			}
			return t;
		}
		node *delete_node(int data,node *head)
		{
			node *temp;
			if(head==NULL)
			{
				return NULL;
			}
			if(data < head->data)
			{
				head->left=delete_node(data,head->left);
			}
			else if(data > head->data)
			{
				head->right=delete_node(data,head->right);
			}
			else if(head->left!=NULL && head->right!=NULL)
			{
				temp=maximum(head->right);
				head->data=temp->data;
				head->right=delete_node(head->data,head->right);
			}
			else {
				temp=head;
				if(head->left==NULL)
				{
					head=head->right;
				}
				else if(head->right==NULL)
				{
					head=head->left;
				}
				delete temp;
			}
			return head;
		}
		node *least_common_node(int d1,int d2,node *head)
		{
			if(head==NULL)
			{
				return NULL;
			}
			if(d1 < head->data && d2<head->data)
			{
				head->left=least_common_node(d1,d2,head->left);
			}
			else if(d1 > head->data && d2>head->data)
			{
				head->right=least_common_node(d1,d2,head->right);
			}
			else if(d1 > head->data && d2 < head->data || d1 < head->data && d2 > head->data)
			{
				cout<<"Parent Node : "<<head->data<<"\n";
				return head;
			}
		}
};
int main()
{
	bst b;
	b.head=b.insert(50,b.head);
	b.insert(65,b.head);
	b.insert(25,b.head);
	b.insert(45,b.head);
	b.insert(20,b.head);
	b.insert(55,b.head);
	b.insert(70,b.head);
	
	b.preorder(b.head);
	
	node *t=b.search(45,b.head);
	cout<<"Found Element : "<<t->data<<" \n";
	
	t=b.minimum(b.head);
	cout<<"\nMinimum Element : "<<t->data<<"\n";
	
	
	t=b.maximum(b.head);
	cout<<"\nMaximum Element : "<<t->data<<"\n";
	
	//t=b.delete_node(65,b.head);
	b.preorder(b.head);
	
	b.least_common_node(45,70,b.head);
}
