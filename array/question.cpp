#include<iostream>
using namespace std;
int main()
{
	int cnt=0;
	int arr[]={9,4,3,2,6};
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(i==j)
			{
				continue;
			}
			if(arr[i]==arr[j])
			{
				cnt++;
			}
		}
		if(cnt>0)
		{
			cout<<"not Distinct values";
			break;
		}
	}
}
