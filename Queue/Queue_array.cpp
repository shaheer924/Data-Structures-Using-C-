#include<iostream>
using namespace std;
#define size 10
class queues{
	public:
		int *queue,top,front;
		queues()
		{
			front=0;
			top=-1;
			queue=new int[size];
			for(int i=0;i<size;i++)
			{
				queue[i]=0;
			}
		}
		int enqueue(int data)
		{
			top++;
			if(top==size-1)
			{
				top=0;
			}
			if(queue[top]!=0)
			{
				cout<<"Queue Is Full \n";
				return 1;
			}
			queue[top]=data;
			if(top==0)
			{
				return 1;
			}
			for(int i=top;i>=1;i--)
			{
				if(queue[i-1]>queue[i])
				{
					swap(queue[i-1],queue[i]);
				}
				else if(queue[i-1]<queue[i]) 
				{
					break;
				}
			}
		}
		void dequeue()
		{
			cout<<queue[front]<<" ";
			queue[front]=0;
			front++;
			if(front==size-1)
			{
				front = 0;
				if(queue[front]!=0)
				{
					cout<<"Queue is Full\n";
				}
			}
		}
		void display()
		{
			for(int i=0;i<=top;i++)
			{
				cout<<queue[i]<<" ";
			}
			cout<<"\n";
		}
};
int main()
{
	queues s1;
	s1.enqueue(10);
	s1.display();
	s1.enqueue(18);
	s1.display();
	s1.enqueue(2);
	s1.display();
	s1.enqueue(16);
	s1.display();
	s1.enqueue(9);
	s1.display();
	s1.dequeue();
	cout<<"\n";
	s1.display();
}
