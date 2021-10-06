// Leaders in an Array
// An element is called leader if no element on right side of it is strictly greater than it.

#include<bits/stdc++.h>
using namespace std;

void leaders(int arr[],int n)
{
	int curr=arr[n-1];	//	Rightmost element will always be a leader.
	cout<<curr<<" ";
	for(int i=n-2;i>=0;i--)
	{
		if(arr[i]>curr)
		{
			curr=arr[i];
			cout<<curr<<" ";
		}
	}
}
int main()
{
	int n;
	cout<<"Enter number of elements: "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	leaders(arr,n);
	return 0;
}

/* Test Case:
I/P:	n=7
	arr[]={7,10,4,3,6,5,2}

O/P: 2 5 6 10
*/
