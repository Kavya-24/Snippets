/*
Given two binary trees, root0 and root1, checks whether their structure and values are equal.

In the given example we are checking

Tree 1:
   0
  /
 5

 Tree 2:
 0
  \
   5
*/


#include<bits/stdc++.h>
using namespace std;

struct Tree {
        int val;
        Tree *left = nullptr;
        Tree *right = nullptr;
};

//checks if the trees are same both structurally and value wise
bool solve(Tree* root0, Tree* root1) {
    if (root0 == nullptr && root1 == nullptr) return true;

    //if only one of the nodes is presnt or if both are present but value is not same
    if (!root0 || !root1 || root0->val != root1->val)
        return false;
    //recursively checking the left and right subtrees
    else
        return (solve(root0->right, root1->right) && solve(root0->left, root1->left));
}

int main(){

  //Tree 1
  Tree *first = new Tree();
  first->val = 0;
  first->left = new Tree();
  first->left->val = 5;

  //Tree 2
  Tree *second = new Tree();
  second->val = 0;
  second->right = new Tree();
  second->right->val = 5;

  if(solve(first,second))
    cout<<"Trees are identical.";
  else
    cout<<"Trees are not identical.";

}
