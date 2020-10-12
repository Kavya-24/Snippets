#include <bits/stdc++.h>
using namespace std;

/*dynamic allocation of node*/
typedef struct node
{
    int data;
    struct node *next;
}List;

/*insert function*/

List* insert(List* head)
{
    printf("\nEnter data to be inserted\n");
    int key;
    scanf("%d",&key);
    List* new_node = (List*)malloc(sizeof(List));
    /*allocating new_node tpo insert new node to insert
    abd tmp pointer to use it as transvering*/

    new_node->data = key;/*assigning data value in node*/
    new_node->next = NULL;/*assigning next of new_node to null*/

    if(head==NULL){
        head = new_node;
    } else
    {
        List *tmp = head;/*initially tmp points to head*/
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=new_node;

    }
return head;
}

/* Function to remove duplicates from a unsorted linked list */
void duplicate(List *head)
{
    List *ptr1, *ptr2, *dup;
    /*ptr1 = for transversing in loop 2,
    dup = to store the one to be deleted,
    ptr2-for transversing in loop1*/

    ptr1 = head;/*assigning head to ptr1*/

    if(head->next==NULL)
    {
        printf("No duplicate elements.Only 1 element present.\n");
        return;
    }

    /* transversing elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        /* Comparing the picked element with rest
           of the elements */

        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else /* If data not equal,transverse 2nd pointer--ptr2 */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
/*reverse LL*/
List* reverseLL(List *head)
{
    List* tmp, *curr,*prev,*nex;
    curr = head;
    prev = NULL;
    if(head==NULL||head->next==NULL)
    {
        return head;
    }else
    {
        while(curr!=NULL)
        {
            nex = curr->next;/* 1 2 3 4*/
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        head = prev;
    }
    return head;
}
/*printing linked List*/
List* display(List* t)
{
    /*t as head here is transversed so that we can print all the data*/
    while(t!=NULL){
        printf("%d\t",(t->data));
        t=t->next;
    }
}

int main()
{
     List *head = NULL;

    cout<<"Enter no of elements in SLL\n";
    int n,a;
    cin>>n;
    while(n>0)
    {
        head = insert(head);
        n--;
    }

    /*performing of the function*/
    do
    {
        /*Various operations performed*/
        printf("\nEnter the operation NO to perform:\n");
        printf("1:Insert  2.Delete duplicate  3.Display LL  4.Reverse SLL ");
        printf("5:Exit\n");
        scanf("%d",&a);


        switch(a)
        {
            case 1:
                head = insert(head);
                break;

            case 2:
                duplicate(head);
                break;

            case 3:
                display(head);
                break;
            case 4:
                head = reverseLL(head);
                break;

            case 5:
                printf("\nExiting.... Have a nice day!\n");
                break;

            default:
                printf("\nEnter valid operation!\n");
        }

    }
    while(a!=5);


    return 0;
}
