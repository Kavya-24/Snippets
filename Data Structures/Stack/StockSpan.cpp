// Stock Span Problem

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter number of days: "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter Prices of Stock for each day: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	stack<int> s;
	s.push(0);
	for(int i=0;i<n;i++)
	{
		while(s.empty()==false && arr[s.top()]<=arr[i])
		{
			s.pop();
		}
		int span=(s.empty()) ? (i+1) : (i-s.top());
		cout<<span<<" ";
		s.push(i);
	}
	return 0;
}

/* Test Case
I/P: n=10
	arr[]={15,13,12,14,16,8,6,4,10,30}
	
O/P: 1 1 1 3 5 1 1 1 4 10
*/
