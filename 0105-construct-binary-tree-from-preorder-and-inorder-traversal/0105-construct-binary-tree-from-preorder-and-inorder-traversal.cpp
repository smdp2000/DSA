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
    
    TreeNode* getBinaryTree(vector<int>& preorder, vector<int>& inorder, int &rootindx, int left, int right){
        
        if (left>right) return NULL;
            
        int pivot=0;
        
        while(preorder[rootindx]!=inorder[pivot]) pivot++;
        
        TreeNode* node= new TreeNode(preorder[rootindx]);
        rootindx++;
        
        node->left = getBinaryTree(preorder, inorder,rootindx, left, pivot-1);
        node->right = getBinaryTree(preorder, inorder,rootindx, pivot+1, right);
        
        return node;

        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootindx=0;
        
        return getBinaryTree(preorder, inorder,rootindx, 0, preorder.size()-1);
        
        
    }
};