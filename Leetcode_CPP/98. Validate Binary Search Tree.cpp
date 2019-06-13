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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        int maxv, minv;
        return dfs(root, maxv, minv);
    }

    bool dfs(TreeNode* root, int &maxv, int &minv)
    {
        maxv = root->val;
        minv = root->val;
        if (root->left)
        {
            int nowMaxv, nowMinv;
            if (!dfs(root->left, nowMaxv, nowMinv))
                return false;
            if (nowMaxv >= root->val)
                return false;
            maxv = max(maxv, nowMaxv);
            minv = min(minv, nowMinv);
        }
      
        if (root->right)
        {
            int nowMaxv, nowMinv;
            if (!dfs(root->right, nowMaxv, nowMinv))
                return false;
            if (nowMinv <= root->val)
                return false;
            maxv = max(maxv, nowMaxv);
            minv = min(minv, nowMinv);
        }
        return true;
    }
};