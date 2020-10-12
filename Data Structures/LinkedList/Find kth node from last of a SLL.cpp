/*using 2 pointers*/
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

List* last_kth_node(List* head,int k)
{
    if(k<0)
    {

        cout<<"Error ENter k>0\n";
        return NULL;
    }
    List *t1,*t2=head;
    t1 =head;
    int i=1;
    while(i<k)
    {
        t2 = t2->next;
        i++;
    }
    if(t2==NULL) return NULL; /*k>n*/
    if(t2->next==NULL) return t1; /*k=n*/
    else{                         /*k<n*/
        t2 = t2->next;
        while(t2!=NULL)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
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
    int n,k;
    cin>>n;
    while(n>0)
    {
        head = insert(head);
        n--;
    }
    cout<<"Enter last kth node:\n";
    cin>>k;
    List* p = last_kth_node(head,k);
    cout<<"Last kth node = "<<p->data<<endl;
    return 0;
}
