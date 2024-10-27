#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int s, int e)
{
    int mid = s + ((e - s) / 2);

    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    // copy
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = v[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = v[k++];
    }

    // merge
    int index1 = 0;
    int index2 = 0;
    k = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            v[k++] = first[index1++];
        }
        else
        {
            v[k++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        v[k++] = first[index1++];
    }

    while (index2 < len2)
    {
        v[k++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(vector<int> &v, int s, int e)
{

    if (s >= e)
    {
        return;
    }

    int mid = s + ((e - s) / 2);

    mergeSort(v, s, mid);
    mergeSort(v, mid + 1, e);

    merge(v, s, e);
}

int main()
{
    // Your code here

    vector<int> v = {3, 7, 1, 9, 2, 5, 8, 2};

    mergeSort(v, 0, v.size() - 1);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}