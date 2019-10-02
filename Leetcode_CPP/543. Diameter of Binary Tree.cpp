// 题目描述
// 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径穿过或者不穿过根结点。

// 算法
// (递归遍历) O(n)
// 递归函数的返回值定义为从当前结点到叶子结点的最大长度，当前结点为空返回 -1。
// 递归时，分别得到左右子树递归的返回值，则可以更新答案 ans = max(ans, d1 + d2 + 2)；然后返回 max(d1, d2) + 1。

// 时间复杂度
// 每个结点最多仅被遍历一次，故时间复杂度为 O(n)。

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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
    int dfs(TreeNode* r, int& ans){
        if(!r) return -1; 
        int d1 = dfs(r->left,ans);
        int d2 = dfs(r->right,ans);
        ans = max(ans, d1+d2+2); //ans是最长路径，d1+d2+2代表经过该点
        return max(d1,d2)+1;     //dfs返回值是该点往下的最长路径
    }
};