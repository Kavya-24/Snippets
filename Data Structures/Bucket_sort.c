#include <stdio.h>
#include<limits.h>
 
//Function to find maximum element of the array
int max_element(int array[], int size) 
{  
    int max = INT_MIN;  
    for (int i = 0; i < size; i++)
    {
        
        max = array[i];  
    }
    return max;  
}
 
void Bucket_Sort(int array[], int size) 
{  
    int max = max_element(array, size); 
 
    int bucket[max+1];  
 
    for (int i = 0; i <= max; i++)  
    bucket[i] = 0;  
 
    for (int i = 0; i < size; i++)  
    bucket[array[i]]++;
 
    int j=0;  
    for (int i = 0; i <= max; i++)  
    { 
        while (bucket[i] > 0)  
        {  
            array[j++] = i;  
            bucket[i]--;   
        }  
    }  
}  
 
int main()
{
    int array[100], i, num; 
 
    printf("Enter the size of array: ");   
    scanf("%d", &num);   
    printf("Enter the %d elements to be sorted:\n",num); 
    for (i = 0; i < num; i++)
    scanf("%d", &array[i]); 
    printf("\nThe array of elements after sorting: \n"); 
    Bucket_Sort(array, num); 
    for (i = 0; i < num; i++)
    printf("%d ", array[i]);   
    printf("\n");     
    return 0;
}
