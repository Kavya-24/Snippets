#include<iostream>
using namespace std;

int maximumElement(int arr[],int n)
{
    int l=0,h=n-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
        {
            return mid;
        }
        else
        {
            if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])
                h=mid-1;
            else
                l=mid+1;
        }
    }
    return -1;
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
    int x = maximumElement(arr,n);
    if(x!=-1)
        cout<<"Element found at index "<<x;
    else
        cout<<"Element not found";
    return 0;
}