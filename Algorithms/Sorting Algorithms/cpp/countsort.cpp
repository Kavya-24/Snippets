#include<iostream>
using namespace std;

void countsort(int arr[],int n,int k)
{
    int count[k+1];
    int b[n];

    for(int i=0;i<=k;i++)
    {
        count[i]=0;
    }              

    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }                               

    for(int i=1;i<=k;i++)
    {
        count[i]=count[i]+count[i-1];
    }           

    for(int i=n-1;i>=0;i--)     
    {
        b[--count[arr[i]]]=arr[i];
        count[arr[i]]--;
    }             

    for(int i=0;i<n;i++)       
    {
        arr[i]=b[i];
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
}

int main()
{
int n;
cout<<"\n How many elements you want to enter: ";
cin>>n;
int arr[n];

   for(int i=0;i<n;i++)
    {
         cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
    }

int k=arr[0];
  for(int i=1;i<n;i++)
    {
    if(arr[i]>k)
    k=arr[i];
    }

 countsort(arr,n,k);

cout<<"the sorted array is: ";
   for(int i=0;i<n;i++)
   cout << arr[i] << ", ";
  cout << endl;
}