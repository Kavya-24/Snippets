#include<iostream>

using namespace std;

/*
Problem statement: you are given a singly link list and you need to find the value of the middle node of the link list.
*/

// defining the structure of node:
struct node
{
    struct node*next;
    int val;
};


class LinkList{
    struct node*head = NULL;
    struct node*curr = NULL;
    public:

    // This method will add a new node at the end of the link list.
    void insertNode(int val){
        struct node* newNode = new struct node;
        if(head == NULL){
            newNode->val = val;
            newNode->next = NULL;
            head = newNode; 
            curr = head;
        }
        else{
            newNode->val = val;
            newNode->next = NULL;
            curr->next = newNode;
            curr = newNode;
        }
    }

    // This method will traverse and display all the values in the link list.
    void displayLinkList(){
        struct node*temp = head;
        if(temp == NULL) cout<<"The link list is empty"<<endl;
        else{
            while(temp != NULL){
                cout<<temp->val<<" ";
                temp = temp->next;
            }

            cout<<endl;
        }
    }

    // This method will give the value of the middle node in the link list.
    void getMiddleNode(){

        // declaring the fast and slow pointers
        struct node*slowPointer, *fastPointer; 
        slowPointer = NULL;
        fastPointer = head;

        if(head == NULL) cout<<"The link list is empty"<<endl;
        else{
            /*
            Run this while loop until the fastpointer reaches to the end of link list.
            slowPointer will take one step in each iteration, whereas the fastPointer will 
            take two steps in each iteration.
            */
            while(fastPointer != NULL){
                
                if(fastPointer == head){
                    slowPointer = head;

                    fastPointer = fastPointer->next;
                    if(fastPointer != NULL) fastPointer = fastPointer->next;
                }
                else{
                    slowPointer = slowPointer->next;

                    fastPointer = fastPointer->next;
                    if(fastPointer != NULL) fastPointer = fastPointer->next;
                }
            }

            cout<<slowPointer->val<<endl;

        }
    }
};

int main(){

    LinkList linkList; // creating the object of LinkList class.

    // creating the link list.
    linkList.insertNode(2);
    linkList.insertNode(3);
    linkList.insertNode(5);
    linkList.insertNode(6);
    linkList.insertNode(6);

    cout<<"This is the link list:"<<endl;
    linkList.displayLinkList();

    cout<<"The middle element of the link list:"<<endl;
    linkList.getMiddleNode();

    return 0;
}