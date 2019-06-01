/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
      TreeNode* p=root;
      while(p){
        st.push(p);
        p=p->left;
      }
    }
    
    /** @return the next smallest number */
    int next() {
      TreeNode* cur=st.top();
      st.pop();
      int res=cur->val;
      cur=cur->right;
      while(cur){
        st.push(cur);
        cur=cur->left;
      }
      return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */