// Intersection of Two Sorted Arrays
// Time Complexity: O(m+n)
// Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

void intersection(int arr1[],int arr2[],int m,int n)
{
	int i=0,j=0;
	while(i<m && j<n){
		if(i>0 && arr1[i-1]==arr1[i])		//To avoid duplicate elements
		{
			i++;
			continue;
		}
		if(arr1[i]<arr2[j])
		{
			i++;
		}
		else if(arr2[j]<arr1[i])
		{
			j++;
		}
		else{
			cout<<arr1[i]<<" ";
			i++;
			j++;
		}
	}	
}
int main()
{
	int m,n;
	cout<<"Enter sizes for both Arrays: "<<endl;
	cin>>m>>n;
	int arr1[m],arr2[n];
	cout<<"Enter Elements for Array 1: "<<endl;
	for(int i=0;i<m;i++)
	{
		cin>>arr1[i];
	}
	cout<<"Enter Elements for Array 2: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr2[i];
	}
	
	intersection(arr1,arr2,m,n);
	return 0;
}

/* Test Case:
I/P:
	m=5	n=7
	arr1[]=[2,5,8,13,15]
	arr2[]=[1,3,8,15,18,20,25]
O/P:
	8 15
*/	
	

	
	
	

