/*
Time Complexity : O(n * log(n)) Space Complexity : O(n)
where n is size of input array
*/

#include <iostream>
#include "solution.h"
using namespace std;

void merge(int input1[], int size1, int input2[], int size2, int output[])
{
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (input1[i] < input2[j])
        {
            output[k] = input1[i]; k++;
            i++;
        }
        else
        {
            output[k] = input2[j]; j++;
            k++;
        }
    }
    while (i < size1)
    {
        output[k] = input1[i]; k++;
        i++;
    }
    while (j < size2)
    {
        output[k] = input2[j]; j++;
        k++;
    }
}

void mergeSort(int input[], int size)
{
    if (size <= 1)
    {
        return;
    }
    int mid = size / 2;
    int part1[500], part2[500];
    int size1 = mid, size2 = size - mid; for (int i = 0; i < mid; i++)
    {
        part1[i] = input[i];
    }
    int k = 0;
    for (int i = mid; i < size; i++)
    {
        part2[k] = input[i]; k++;
    }
    mergeSort(part1, size1); mergeSort(part2, size2);
    merge(part1, size1, part2, size2, input);
}

//Driver Code

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
