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
    void dfs(TreeNode* cur, vector<TreeNode*>& nodeList) {
      if(!cur) return;
      if(cur->left) dfs(cur->left,nodeList);
      nodeList.push_back(cur);
      if(cur->right) dfs(cur->right, nodeList);
    }
  
    int kthSmallest(TreeNode* root, int k) {
      vector<TreeNode*> nodeList;
      dfs(root,nodeList);
      return nodeList[k-1]->val;
    }
};