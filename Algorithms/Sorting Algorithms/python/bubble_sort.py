def BubbleSort(arr):

    # this loop is for the passes
    for i in range(len(arr)-1):
        # this loop is for the comparisions
        for j in range(0,len(arr)-1-i):
            if(arr[j]>arr[j+1]):
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp

    # finally return the array
    return arr


# testing the BubbleSort function
lt = [5,3,7,3,7,9]

res = BubbleSort(lt)
print(res)