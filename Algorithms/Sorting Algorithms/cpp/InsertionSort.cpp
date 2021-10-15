#include <iostream>
using namespace std;


void insertionSort(int *arr, int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        temp = arr[i];
        j = i-1;
        while(j >=0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int size,i;
    cout<<"Enter the size of the array : ";
    cin>>size;
    int arr[size];

    for(i=0;i<size;i++)
        cin>>arr[i];
    
    insertionSort(arr,size);
    
    for(i=0;i<size;i++)
        cout<<arr[i]<<" ";

    return 0;
}

