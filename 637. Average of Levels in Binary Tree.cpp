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
    void dfs(TreeNode* cur, int level, vector<double>& ans,vector<int>& counter){
        if(!cur) return;
        if(level==ans.size()){
          ans.push_back(0);
          counter.push_back(0);
        }
        ++counter[level];
        ans[level]+=cur->val;
        dfs(cur->left,level+1,ans,counter);
        dfs(cur->right,level+1,ans,counter);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<int> counter;
        dfs(root,0,ans,counter);
        for(int i=0;i<ans.size();++i)
          ans[i]/=counter[i];
        return ans;
        
    }
};