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
        int target=arr[start]+arr[end];
        if(target>x)
            end--;
        else
        if(target<x)
            start++;
        else
        {
            cout<<start<<" "<<end;
            return 1;
        }
    }
    cout<<"pair not present";
    return 0;
}
