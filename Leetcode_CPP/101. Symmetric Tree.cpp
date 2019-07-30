/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* p, TreeNode* q){
        if(!p||!q) return !p&&!q;
        return p->val==q->val && dfs(p->left,q->right) && dfs(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return !root || dfs(root->left, root->right);
    }
};