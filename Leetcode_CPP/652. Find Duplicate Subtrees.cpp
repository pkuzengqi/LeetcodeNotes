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
    unordered_map<string,int> hash;
    vector<TreeNode*> ans;
  
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      dfs(root);
      return ans;
    }
  
    string dfs(TreeNode* root){
      if(!root) return "";

      auto left = dfs(root->left);
      auto right = dfs(root->right);
      string cur = to_string(root->val) + "," + left + "," +right;
      
      if(hash[cur]==1) ans.push_back(root);
      hash[cur]++;
      return cur;
    }
};