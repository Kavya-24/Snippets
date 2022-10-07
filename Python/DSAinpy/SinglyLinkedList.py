#Insert a singly linked list at the end of the list
class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
 
    
    def getValueAt(self, index):
        current = self.head  
        count = 0

        while (current):
            if (count == index):
                print(current.val)
            count += 1
            current = current.next
        return 0

    def addAtEnd(self, val):
        newNode = Node(val)

        if self.head == None:
            self.head = newNode
            self.tail = newNode

        else:
            self.tail.next = newNode
            self.tail = newNode
    
    def display(self):
        current = self.head

        if self.head == None:
            print("The Linked list is empty")
            return
        while current != None:
            print(current.val)
            current = current.next

    def getHead(self):
        print(self.head.val)
    

ll = SinglyLinkedList()

ll.addAtEnd(80)
ll.addAtEnd(8)
ll.addAtEnd(59)

ll.display()
ll.getHead()

ll.getValueAt(2)
