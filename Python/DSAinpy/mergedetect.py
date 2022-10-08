class Node:
    def __init__(self, dataval=None):
        self.data = data
        self.next = None

def detectMerge(list1,list2):
    temp1 = list1
    temp2 = list2
    while temp1 != None:
        while temp2 != None:
            if temp1 == temp2:
                return True
            temp2 = temp2.self.next
        temp2 = list2
        temp1 = temp1.next
    return False    
    

if __name__ == "__main__":
    list1 =[1,2,3,4,5]
    list2 = [7,8, 4,5]

if detectMerge(list1,list2):
    print('Merged')
else:
    print('Not Merged')

