#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void main()
{
    struct node *p, *head;
    int n, i;
    printf("How many nodes to be created\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            head = (struct node *)malloc(sizeof(struct node));
            p= head;
        }
        else
        {
            p->next = (struct node *)malloc(sizeof(struct node));
            printf("Enter the value: ");
            scanf("%d", &p->next->data);
        }
        p = p->next;
    }
    p->next = NULL;
    p = head;
    while (p->next != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
}
