#include<iostream>
using namespace std;

void frequency1(int arr[],int n)
{
    int l=0,h=n-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]==0)
        {
            l=mid+1;
        }
        else
        if(arr[mid]==1 && arr[mid-1]==0)
        {
            cout<<"frequency of 1 = "<<n-mid;
            return;
        }
        else
        if(arr[mid]==1)
        {
            h=mid-1;
        }
    }
    cout<<"1 is not present";
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(arr[0]==1)
    {
        cout<<"frequency of 1 = "<<n;
    }
    else
    {
        frequency1(arr,n);
    }
    return 0;
}