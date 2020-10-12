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

List* midnode(List* head)
{
    List *t1=head,*t2 = head;
    if(t1==NULL||t1->next==NULL||t1->next->next==NULL)
    {
        return head;
    }
    /*assume odd no of nodes at least 3 elements for middle element to exist*/
    while(t2!=NULL&&t2->next!=NULL)
    {
        t2=t2->next->next;
        t1=t1->next;
    }
    return t1;
}

/*printing linked List*/
void display(List* t)
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
    List* p = midnode(head);
    cout<<p->data<<endl;
    return 0;
}
