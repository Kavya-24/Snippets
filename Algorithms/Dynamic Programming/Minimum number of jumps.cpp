// Minimum number of jumps

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0 ; i< n ; i++)
		cin>>arr[i];

	int min_setp[n], from[n];
	fill_n(min_setp, n, n+100);
	min_setp[0] = 0;
	from[0] = 0;

	for(int j=0 ; j<n ; j++)
	{
		if(min_setp[j] == n+100)
		{
			cout<<-1<<endl;
			return;
		}
		for(int i=j+1 ; i<=j+arr[j] && i<n ; i++)
		{
			if(1 + min_setp[j] < min_setp[i])
			{
				min_setp[i] = 1 + min_setp[j];
				from[i] = j;
			}
		}
	}

	cout<<min_setp[n-1];

	return;
}

int main()
{
	solve();
	return 0;
}