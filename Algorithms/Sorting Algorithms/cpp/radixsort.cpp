#include<iostream>
using namespace std;

int getMax(int arr[],int n)
{
  int max=arr[0];
  for(int i=1;i<n;i++)
  {
      if(arr[i]>max)
      max=arr[i];
  }
  return max;
}

void countsort(int arr[],int n,int pos)
{
    int k=9;
    int count[k+1]={0};
    int b[n];

    /*for (int i = 0; i <= k; i++)
    {
        count[i] = 0;
    }*/
    for(int i=0;i<n;i++)
    {
        count[(arr[i]/pos)%10]++;
    }
    for(int i=1;i<=9;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        b[count[(arr[i]/pos)%10]-1]=arr[i];
        count[(arr[i]/pos)%10]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=b[i];
    }
}

void radixsort(int arr[],int n)
{
    int max=getMax(arr,n);

    for(int pos=1;max/pos>0;pos*=10)
    {
    countsort(arr,n,pos);
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
  
 radixsort(arr,n);

 cout<<"the sorted array is: ";
   for(int i=0;i<n;i++)
   cout << arr[i] << ", ";
  cout << endl;
}