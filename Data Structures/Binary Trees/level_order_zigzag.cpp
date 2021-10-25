#include <iostream>
#include <queue>
#include <algorithm>
#include<stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}
void zigzag(node *root)
{
    if(!root){
        return;
    }
    stack<node *> curr;
    stack<node *> nextlevel;
    curr.push(root);
    bool lr = true;
    while (!curr.empty())
    {
        node *temp = curr.top();
        curr.pop();
        if (temp)
        {
            
            cout << temp->data << " ";
            if (lr)
            {
                if (temp->left)
                {
                    nextlevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextlevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextlevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextlevel.push(temp->left);
                }
            }
        }
        if (curr.empty())
        {
            lr=!lr;
            swap(curr,nextlevel);
        }
    }
}
int main()
{
    node *root = build("true");
    zigzag(root);
    return 0;
}
