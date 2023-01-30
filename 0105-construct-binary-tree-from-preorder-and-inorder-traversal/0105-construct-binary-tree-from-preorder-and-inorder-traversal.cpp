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
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right){
        if(left>right) return NULL;
        
        int pivot = left;
        
        while(preorder[rootIdx]!=inorder[pivot]) pivot++;
        
        TreeNode* root = new TreeNode(inorder[pivot]);

                rootIdx++;

        root->left = build(preorder, inorder, rootIdx, left, pivot-1 );
        root->right = build(preorder, inorder, rootIdx, pivot+1, right);
        
        return root;
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    int rootindx = 0;
    return build(preorder, inorder, rootindx, 0, preorder.size()-1);
        
    }
};