class Node:
    def __init__(self, dataval=None):
        self.data = data
        self.next = None
        
def detectMerge(list1,list2):
    temp1 = list1
    temp2 = list2
    len1 = len(temp1)
    len2 = len(temp2)
    
    while len1 != len2:
        if len1> len2:
            temp1 = temp1.next
            len1 = len1 -1

        else:
            temp2 = temp2.next
            len2 = len2 -1

    while temp1 != None:
        if temp1 == temp2:
            return True
        temp1 = temp1.next
        temp2 = temp2.next
    return False

def findLen(head):
    len = 0
    while head != None:
        len = len +1
        head = head.next
    return len 
      
    


list1 =[1,2,3,4,5]
list2 = [7,8, 4,5]
detectMerge(list1,list2)

