class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>level;
        if(!root)return level;
        while(!q.empty()){
            int size = q.size();
            vector<int>sublevel;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node!=NULL){
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(anode->right);
                    sublevel.push_back(node->val);
                }
                else{
                    sublevel.resize(0);
                    if(q.size() > 0) q.push(NULL);
                }
            }
            level.push_back(sublevel);
        }
        return level;
    }
};
