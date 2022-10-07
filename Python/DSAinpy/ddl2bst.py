#Code in python to convert Doubly linked list into Binary search tree
class ListNode:
    #init method for creating nodes
    def __init__(self, x):
        self.val = x
        self.next = None
        self.prev = None

class BST:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def findMiddle(self, head):
        prevPtr = None
        slowPtr = head
        fastPtr = head

        while fastPtr and fastPtr.next:
            prevPtr = slowPtr
            slowPtr = slowPtr.next
            fastPtr = fastPtr.next.next

        if prevPtr:
            prevPtr.next = None

        return slowPtr

    def sortedListToBST(self, head):        
        if head== None:
            return None
        
        if head.next == None:
            return BST(head.val)
        mid = self.findMiddle(head)
        node = BST(mid.val)
        node.left = self.sortedListToBST(head)
        node.right = self.sortedListToBST(mid.next)
        return node

def main():
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node4 = ListNode(4)
    node5 = ListNode(5)
    node6 = ListNode(6)
    node7 = ListNode(7)
    node8 = ListNode(8)
    node9 = ListNode(9)

    node1.next = node2
    node2.prev = node1
    node2.next = node3
    node3.prev = node2
    node3.next = node4
    node4.prev = node3
    node4.next = node5
    node5.prev = node4
    node5.next = node6
    node6.prev = node5
    node6.next = node7
    node7.prev = node6
    node7.next = node8
    node8.prev = node7
    node8.next = node9
    node9.prev = node8

    sol = Solution()
    tree = sol.sortedListToBST(node1)
    printTree(tree)


def printTree(root):
    if root == None:
        return 
    print(root.val)
    printTree(root.left)
    printTree(root.right)

main()