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
    int minDepth(TreeNode* root) {
      if(!root) return 0;
      int res=INT_MAX;
      if(root->left) res=min(res,minDepth(root->left)+1);
      if(root->right) res=min(res,minDepth(root->right)+1);
      if(res==INT_MAX) res=1;
      return res;
    }
};