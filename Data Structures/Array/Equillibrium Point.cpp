//Equillibrium Point in an Array

#include<bits/stdc++.h>
using namespace std;

int EqPoint(int arr[],int n)
{
	int left_sum=0,total_sum=0;
	for(int i=0;i<n;i++)
	{
		total_sum+=arr[i];
	}
	for(int i=0;i<n;i++)
	{
		if(left_sum == total_sum-arr[i])
			return i;
		left_sum+=arr[i];
		total_sum-=arr[i];
	}
	return -1;
}
int main()
{
	int n;
	cout<<"Enter Number of Elements: "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter Array Elements: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int point=EqPoint(arr,n);
	if(point==-1)
		cout<<"No Equillibrium Point exists in the Array"<<endl;
	else
		cout<<"Equillibrium Point exists at index: "<<point<<endl;
	
	return 0;
}


