//PROGRAM TO FIND IF THERE EXIST ANY PAIR OF ELEMENTS SUCH THAT THEIR SUM IS 
//EQUAL TO x

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int start=0,end=n-1;
    while(start<end)
    {
        if(arr[start]+arr[end]>x)
            end-=1;
        else
        if(arr[start]+arr[end]<x)
            start+=1;
        else
        if(arr[start] + arr[end] == x)
        {
            cout<<start<<" "<<end;
            return 1;
        }
    }
    cout<<"pair not present";
    return 0;
}