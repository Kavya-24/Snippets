// Stack implementation in C++

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
#define MAX 100

class stack
{
    char string[MAX];
    int top;

public:
    stack()
    {
        top = -1;
    }

    int isfull();
    int isempty();
    void push();
    void pop();
    void printStack();
};

// Check if the stack is full
int stack ::isfull()
{
    return (top == MAX - 1) ? 1 : 0;
}

// Check if the stack is empty
int stack ::isempty()
{
    return (top == -1) ? 1 : 0;
}

// Add elements into stack
void stack ::push()
{
    if (isfull())
    {
        cout << "STACK IS FULL";
    }

    else
    {
        char str[31];
        int i = 0;
        cout << "Enter a string (not more than 30 characters) :- \t";
        cin.getline(str , 30);

        if (strlen(str) > 31){
            cout << "Entered string is more than 30 characters ";
            return;
        }
        top = top + strlen(str);
        for (auto x : str)
        {
            string[i] = x;
            i++;
        }
    }
}


void stack ::pop()
{
    if (isempty())
    {
        cout << "\nSTACK IS EMPTY \n";
    }

    else
    {
        cout << "Reversed string is :- \t";
        for (auto i = top; top >= 0; top--)
            cout << string[top];
    }

    // top = -1;

    cout << endl;
}

// Print elements of stack
void stack ::printStack()
{
    if (!(isempty()))
    {
        cout << "Stack isn't empty " << endl;
        printf("Value of top is %d", top);
        printf("\nOriginal String :- \t");
        cout << string;
        cout << endl;
        // top = -1;
    }
}

// Driver code
int main()
{
    stack st;
    int ch;

    cout << "\nChose any of the following options :" << endl;
    cout << "\n0: Exit \n1: Enter a string (push) \n2: Print Reversed String (pop) \n3: Print Queue" << endl;
    cout << "\n\n";
    cout << "Your choice :- ";
    cin >> ch;

    switch (ch)
    {
    case 0:
        exit(0);
    case 1:
        st.push();
        break;
    case 2:
        st.pop();
        break;
    case 3:
        st.printStack();
        break;
    default:
        cout << "Please choose a correct option!" << endl;
        break;
    }

    return 0;
}