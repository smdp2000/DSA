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
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        
       goLeft(root);
        
        
    }
    
    int next() {
            
            TreeNode *r = st.top();
            st.pop();
            if(r->right!=NULL){
                goLeft(r->right);
                
            }
        
        return r->val;
        
    
    
        
    }
    
    bool hasNext() {
        
        if(!st.empty())
            return true;
        
        return false;
        
    }
    
    void goLeft(TreeNode* root){
        TreeNode* l = root;
        while(l!=NULL){
            st.push(l);
            l= l->left;
        }
    }
        
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */