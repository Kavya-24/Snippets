void rvereseArray(int arr[], int start, int end)
{
    while (start < end)
        swap(arr[start++],arr[end--]);
}    
