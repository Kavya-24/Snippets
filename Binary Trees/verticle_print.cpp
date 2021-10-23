#include <bits/stdc++.h>
using namespace std;

class node {
	public:
		int data;
		node *left;
		node *right;
	node(int d){
		data=d;
		left = NULL;
		right = NULL;
	}	
};

node* buildTreeLevelWise(){

	int d;
	cin>>d;

	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){

		node*f = q.front();
		q.pop();
		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			f->left = new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}

void vop(node *root,map<int,vector<int>> &m,int d)
{
    if(root==NULL)
     return;
    m[d].push_back(root->data);
    vop(root->left,m,d-1);
    vop(root->right,m,d+1);
}
int main(){
    int n;
    cin>>n;
    node * root = buildTreeLevelWise();
       map<int,vector<int> > m;
       vop(root,m,0);
      for(auto it=m.begin();it!=m.end();it++)
	{   
	    for(int j=0;j<it->second.size();j++)
	      {
              cout<<it->second[j]<<" ";
          }
	      cout<<endl;
	}
    return 0;
}
