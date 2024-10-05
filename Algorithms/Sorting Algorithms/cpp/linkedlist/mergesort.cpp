// In this code script we have done "sorting of linked list using mergesort"
#include<iostream>
using namespace std;

/*
    We created a class named as node 
    In which put data and its next
    and made a constructor.
*/

class node {                     
    public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to insert a node at the end of the linked list
void insertAtTail(node* &head, int data) {
    node* newNode = new node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to find the middle of the linked list
node* findmid(node* head) {
    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
node* merge(node* left, node* right) {
    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    node* ans = new node(-1);
    node* temp = ans;

    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

// Function to perform merge sort on a linked list
node* MergeSort(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* mid = findmid(head);

    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    left = MergeSort(left);
    right = MergeSort(right);

    node* result = merge(left, right);
    return result;
}

int main() {
    node* head = NULL;
    int choice;
    int data, n;
                                                                        // used switch case to ask user what to do
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert elements into linked list\n";
        cout << "2. Sort the linked list using Merge Sort\n";
        cout << "3. Display the linked list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "How many values would you like to insert? ";
                cin >> n;
                cout << "Enter " << n << " values: ";
                for (int i = 0; i < n; i++) {
                    cin >> data;
                    insertAtTail(head, data);
                }
                break;
            
            case 2:
                head = MergeSort(head);
                cout << "Linked list sorted using Merge Sort.\n";
                break;
            
            case 3:
                cout << "Current Linked List: ";
                printList(head);
                break;
            
            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
