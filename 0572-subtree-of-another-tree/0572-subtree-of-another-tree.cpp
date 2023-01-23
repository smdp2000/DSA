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
    
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(root==NULL || subRoot==NULL)
            return root==subRoot;
           
         return root->val==subRoot->val && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root==NULL )
            return root==subRoot;
        
        if(subRoot==NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        int flag = false;
        while(!q.empty()){
            
            TreeNode* cur = q.front();
                q.pop();
                if(cur->val==subRoot->val)
                    flag = isSame(cur, subRoot);
                
                if(flag==true)
                        return true;
                
                    if(cur->left!=NULL)
                        q.push(cur->left);
                    
                    if(cur->right!=NULL)
                        q.push(cur->right);
                
            
        }
        
        return flag;
    }
};