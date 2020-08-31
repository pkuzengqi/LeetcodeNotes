# 问题描述

输入一棵二叉树的根结点，判断该树是不是平衡二叉树。

如果某二叉树中任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

注意：

规定空树也是一棵平衡二叉树。


样例
```
输入：二叉树[5,7,11,null,null,12,9,null,null,null,null]如下所示，
    5
   / \
  7  11
    /  \
   12   9

输出：true
```

# 算法

用dfs函数记录高度，跟71题一样

```
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

    bool ans = true;

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode *root)
    {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        if (abs(left - right) > 1) ans = false;
        return max(left, right) + 1;
    }
};

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/25906/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```