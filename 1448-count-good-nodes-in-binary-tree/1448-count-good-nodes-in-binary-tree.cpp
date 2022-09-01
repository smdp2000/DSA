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
void solve(TreeNode* root, int max, int &count){
        if(!root) return;
        if(root->val >= max){
            count++;
            max=root->val;
        }
        solve(root->left,max,count);
        solve(root->right,max,count);
    }
    
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        solve(root,INT_MIN,count);
        return count; 
    }
};