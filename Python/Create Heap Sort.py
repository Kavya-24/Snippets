def heapify(arr, n, i):

    largest = i
    l = 2 * i + 1 
    r = 2 * i + 2 

    if l < n and arr[i] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

#heapsort function
def heapSort(arr,n):

    for i in range(n, -1, -1):
        heapify(arr, n, i)

    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

#input the array
n=int(input("Number of elements in the array:"))
arr=list(map(int, input("elements of array:-").strip().split()))

#sort the array
heapSort(arr,n)

#print the sorted array
print ("Array after implementation of heap sort is:")
for i in range(n):
   print (arr[i],end=" ")
