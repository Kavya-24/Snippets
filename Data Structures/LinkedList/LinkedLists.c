#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Create a struct'
struct Node{

    //Datatype  for str
    char * name;
    int age;
    struct Node * next;
    struct Node * prev;
};



typedef struct Node  node;
///Global head for recursive reverse
node * head;


void printElements(node * head){
    //We have a head pointer
    node * temp = head;
    while(temp != 0){

        printf("Name: %s Age:%d\n",  temp->name,temp->age);
        temp = temp->next;
    }
}

///Print using recursion
void printRecursively(node * x)
{
    if(x==0){
        return;
    }
    printf("Name: %s and Age %d\n", x->name, x->age);
    printRecursively(x->next);

}

///Reverse print using recursions
void reverseR(node * x)
{
    if(x==0){
        return;
    }
    reverseR(x->next);
   printf("Name: %s and Age %d\n", x->name, x->age);

}

///Reverse the list iteratively
node * reverseList(node * head){

  node * nxt = head;
  node * prev = 0;
  node * current = head;
  while(current !=0){
    //While it doesnt reach the end,
    nxt = current->next;
    current->next = prev;
    prev = current;
    current = nxt;
   }

   head = prev;
   printElements(head);
   return head;


}

void reverseListRecursively(node * h)
{
    if(h->next == 0){
        //This is the last node
        head = h;
        return;
    }

    reverseListRecursively(h->next);
    node * temp = h->next;
    temp->next = h;
    h->next = 0;



}


///Insert a node.
node* insertNode(node * head, int k,  char * name, int age)
{

    //Create a node to be added at index k, (add after kth element)
    node * p =(node* ) malloc(sizeof(node));
    p->age = age;
    p->name = malloc(strlen(name)+1);
    strcpy(p->name, name);
    p->next = 0;
    //Next is  transversal
   if(k == 1){
    //Add at the first position
    p->next = head;
    head = p;
    return head;
   }

   else{
    node* temp = head;
    for(int f =0; f<k-2; f++){
        temp = temp->next;
    }

    p->next = temp->next;
    temp->next = p;
   }
    printElements(head);
    return head;
}


node *  deleteNode(node * head, int k)
{
     node* temp = head;
     if(k==1){
      //Delete 1st node
      head = head->next;
     }

    else{
     for(int f = 0; f<k-2 ; f++){
        temp = temp->next;
     }
     node * tempNext = temp->next;
     temp->next  = tempNext->next;

     free(tempNext);
    }

    printElements(head);
    return head;
}


///To convert it in circular linked list, use a pointer to the current and point its next to head.

int main()
{

    //Variable for the head(Start)
    node * head = 0;
    node * p;
    node * now;
    int size;
    int n,m, k;
    char arr[100];
    char newName[100];
     int newAge;


    //To create a node use p as the temporary node
    while(1){
            p = (node *)malloc(sizeof(node));

            //Access p->name or p.name


           printf("Enter the name: ");
           scanf("%s", &arr);
            p->name = malloc(strlen(arr)+1);
            strcpy(p->name, arr);

            printf("Enter the age: ");
            scanf("%d",&(p->age));

            //If it is the first element
            p->next = 0;
            if(head == 0){
                head = p;
                now = p;
            }
            else{
                now ->next = p;
                now = p;
            }
            size ++;

         printf("Press 1 to continue or 0 to exit: ");     //To check weather the user wants to input any number
        scanf("%d", & n);
        if (n == 0) {
            break;
        }

        //Print all the elements
    }

    printElements(head);




   while(1){
    printf("\nTo print the elements of the list, press 1");
    printf("\nTo insert an element in the list, press 2");
    printf("\nTo delete an element in the list, press 3");
    printf("\nTo reverse Iteratively, press 4");
    printf("\nTo reverse recursively, press 5");
    printf("\nTo print recursively, press 6");
    printf("\nPress 0 to exit:");
    scanf("%d", &m);


   switch(m){
     case 0 : return 0;
     case 1: printElements(head);
                break;
     case 2: printf("\nEnter the position where you want to add the item: ");
                 scanf("%d", &k);
                 printf("\nEnter the name you want to enter: ");
                 scanf("%s", &newName);
                 printf("\nEnter the age of the person: ");
                 scanf("%d", &newAge);
                 head = insertNode(head,k, newName, newAge);
                 size++;
                 break;
       case 3 :printf("\nEnter the position where you want to delete the item: ");
                  scanf("%d", &k);
                  head = deleteNode(head, k);
                  size--;
                  break;
     case 4:  ///Dont return head if you want to use initial list as head
                  head = reverseList(head);
                  break;
     case 5 : reverseR(head);
                  break;
     case 6 : printRecursively(head);
                  break;
     default: return 0;

     }

   }

    return 0;
}
