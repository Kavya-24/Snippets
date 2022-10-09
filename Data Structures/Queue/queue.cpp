// Queue implementation in C++

#include <stdlib.h>
#include <iostream>

using namespace std;

int size = 0;
// Creating a Node
class Node
{
public:
    int item;
    Node *next;

    Node()
    {
        item = 0;
        next = nullptr;
    }

    // ~Node(){
    // }
};

// Create a Queue
class Queue
{
    Node *front, *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool is_empty();
    int enqueue(Queue &);
    int dequeue(Queue &);
    void print_queue();
    int peek(Queue &);
    int total_element();
    void end_elements();
};

// Check if the Queue is empty
bool Queue ::is_empty()
{
    return (front == nullptr || (rear == nullptr)) ? 1 : 0;
}

// Insertion at end
int Queue ::enqueue(Queue &q)
{

    int value;
    Node *newnode = (Node *)malloc(sizeof(Node));
    cout << "Enter the value : ";
    cin >> value;
    newnode->item = value;
    newnode->next = nullptr;

    if (q.is_empty())
    {
        front = newnode;
        rear = newnode;
        return 1;
    }

    rear->next = newnode;
    rear = newnode;
    return 1;
}

// Deletion at beginning
int Queue ::dequeue(Queue &q)
{
    Node *temp = front;
    if (front == rear && rear != nullptr)
    {
        cout << temp->item << " is deleted from queue";
        free(temp);
        return (temp->item);
    }

    cout << temp->item << " is deleted from queue";
    front = front->next;
    free(temp);
    return (temp->item);
}

void Queue::print_queue()
{
    Node *temp = front;
    cout << "\n\n Queue :-  [  ";
    while (temp->next != nullptr)
    {
        cout << temp->item << " ,  ";
        temp = temp->next;
    }
    cout << temp->item << "  ] ";
}

int Queue ::total_element()
{
    if ((front == rear) && (rear != nullptr))
    {
        cout << "Currently Queue contain only 1 element";
        return 0;
    }

    int num = 0;
    Node *temp = front;
    while (temp->next != nullptr)
    {
        ++num;
        temp = temp->next;
    }

    cout << "Currently Queue contains " << ++num << " elements.";
    return (num);
}

int Queue ::peek(Queue &q)
{
    int pos;
    int size = q.total_element();
    Node *temp = front;
    cout << "\nAt which position do you want to peek ?  ";
    cin >> pos;

    if (!(pos >= size))
    {
        for (int i = 0; i < pos; i++)
            temp = temp->next;
    }

    cout << "Value [ " << temp->item << " ] is present at position " << pos << " from beginning/front.";
    return 1;
}

void Queue::end_elements()
{
    cout << "\n\n";
    cout << "Queue begins at " << front->item << endl;
    cout << "Queue ends at " << rear->item << endl;
}

// Driver code
int main()
{

    int choice = 0;
    Queue q1;
    cout << "DYNAMIC QUEUE" << endl;
    while (1)
    {
        cout << "\n\nChose any of the following options :" << endl;
        cout << "\n0: Exit \n1: Enqueue \n2: Dequeue \n3: Peek \n4: Check if Queue is empty\n5: Print Queue\n6: Get Number of elements in Queue\n7: Get Starting and Ending Elements" << endl;
        cout << "\n\n";
        cout << "Your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            exit(0);

        case 1:
            q1.enqueue(q1);
            break;

        case 2:
            if (!q1.is_empty())
                q1.dequeue(q1);
            break;

        case 3:
            q1.peek(q1);
            break;

        case 4:
            if (q1.is_empty())
                cout << "Queue is Empty";
            else
                cout << "Queue isn't empty";
            break;

        case 5:
            q1.print_queue();
            break;

        case 6:
            q1.total_element();
            break;

        case 7:
            q1.end_elements();
            break;

        default:
            cout << "Please choose a correct option!" << endl;
        }
    }
}
