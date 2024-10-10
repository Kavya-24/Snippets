

/* 
Problem Statement:
The task is to implement the Merge Sort algorithm, which is a divide-and-conquer algorithm that sorts an array by recursively dividing it into two halves, sorting each half, and then merging the two sorted halves together.
Approach:
1. **Divide**: Recursively split the array into two halves until each subarray contains only one element.
2. **Conquer**: Merge the sorted halves by comparing the elements of the subarrays and placing them in order.
3. **Combine**: Combine the sorted subarrays to form a fully sorted array.
*/
#include <stdio.h>  

/* Function to merge the subarrays of a[] */
void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    // Size of left subarray
    int n2 = end - mid;        // Size of right subarray

    // Temporary arrays to store the divided elements  
    int LeftArray[n1], RightArray[n2];  

    /* Copy data to temp arrays */  
    for (int i = 0; i < n1; i++)    
        LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
        RightArray[j] = a[mid + 1 + j];    

    i = 0; /* Initial index of first sub-array */  
    j = 0; /* Initial index of second sub-array */   
    k = beg;  /* Initial index of merged sub-array */  

    /* Merge the temp arrays back into a[beg...end] */  
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    

    /* Copy the remaining elements of LeftArray[], if any */
    while (i < n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    

    /* Copy the remaining elements of RightArray[], if any */
    while (j < n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    

/* Function to perform Merge Sort */  
void mergeSort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        // Find the middle point
        int mid = (beg + end) / 2;  

        // Recursively sort first and second halves
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  

        // Merge the sorted halves
        merge(a, beg, mid, end);  
    }  
}  

/* Function to print the array */  
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
    printf("\n");  
}  

/* Driver code */  
int main()  
{  
    // Sample array
    int a[] = { 12, 31, 25, 8, 32, 17, 40, 42 };  
    int n = sizeof(a) / sizeof(a[0]); // Calculate size of the array

    printf("Before sorting, array elements are - \n");  
    printArray(a, n);  

    // Call mergeSort
    mergeSort(a, 0, n - 1);  

    printf("After sorting, array elements are - \n");  
    printArray(a, n);  

    return 0;  
}  
