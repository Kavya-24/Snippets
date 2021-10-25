/*
symmetric Binary Tree
Given the root to a binary tree root, check whether it is symmetric.
Eg: The following tree is symmetric:

     0
   /   \
  2     2
 / \   / \
5   1 1   5

*/

#include <bits/stdc++.h>
using namespace std;

struct Tree {
      int val;
      Tree *left = nullptr;
      Tree *right = nullptr;
      Tree(int n){
        val = n;
      }
  };

bool isSame(Tree* root1, Tree* root2) {
    if(!root1 && !root2)
        return true;
    //only one of the nodes is present or both are present but values are different
    if(!root1 || !root2 || root1->val != root2->val) {
        return false;
    }

    //recursively checking on their child nodes
    return isSame(root1->left, root2->right) && isSame(root1->right, root2->left);
}

bool isSymmetric(Tree* root) {
    if(!root)return true;
    return isSame(root->left, root->right);
}

int main(){
  
  Tree* root = new Tree(0);
  root->left = new Tree(2);
  root->right = new Tree(2);
  root->left->left = new Tree(5);
  root->left->right = new Tree(1);
  root->right->left = new Tree(1);
  root->right->right = new Tree(5);

  if(isSymmetric(root))
    cout<<"The binary tree is symmetric.";
  else
    cout<<"The binary tree is not symmetric.";
  return 0;
}
