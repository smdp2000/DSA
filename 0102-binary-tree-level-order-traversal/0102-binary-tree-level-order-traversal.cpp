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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans(1);
                if(root==NULL)
                    return {};

        queue<pair<TreeNode*, int>>q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            
            pair<TreeNode*, int> p = q.front();
            q.pop();
            ans.push_back(vector<int>());
            ans[p.second].push_back(p.first->val);
            if(p.first->left!=NULL){
                //ans.resize(p.second+2);
                q.push(make_pair(p.first->left, p.second+1));}
            if(p.first->right!=NULL){
               // ans.resize(p.second+2);
                q.push(make_pair(p.first->right, p.second+1));}
            
        }
for (int i = 0; i < ans.size(); ) {
    if (ans[i].size() == 0) {
        ans.erase(ans.begin() + i);
    } else ++i;
}
        return ans;
        
    }
};