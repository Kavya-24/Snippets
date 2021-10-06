#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

int height(Node *root){
    if(root==NULL)
        return 0;
    else
        return (1+max(height(root->left),height(root->right)));
}

bool isBalanced(Node *root){
    if(root==NULL)
        return true;
    int lh=height(root->left);
    int rh=height(root->right);
    return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));
}

int main() {
	
	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(30);
	root->right->left=new Node(15);
	root->right->right=new Node(20);
	
	cout<<isBalanced(root);
}
