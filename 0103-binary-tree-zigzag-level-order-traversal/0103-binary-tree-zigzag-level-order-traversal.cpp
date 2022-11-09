/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>zigzag;
        if(root==NULL)
            return zigzag;
        queue<TreeNode*>q;
        q.push(root);
        int lr =1;
        while(!q.empty()){
            int size = q.size();
            vector<int>row(size);
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                int index = lr ? i : size-1-i;    
                row[index] = node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }  
                
            lr=!lr;
            zigzag.push_back(row);
                
            }
            
            return zigzag;
        }
        
    
};