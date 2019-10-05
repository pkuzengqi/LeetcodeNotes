// 题目描述
// 给定一棵二叉树的前序遍历和中序遍历，请复原出整棵二叉树。

// 注意：二叉树中没有值相同的节点。


// 算法
// (递归) O(n)
// 递归建立整棵二叉树：先递归创建左右子树，然后创建根节点，并让指针指向两棵子树。

// 具体步骤如下：
// 先利用前序遍历找根节点：前序遍历的第一个数，就是根节点的值；
// 在中序遍历中找到根节点的位置 kk，则 kk 左边是左子树的中序遍历，右边是右子树的中序遍历；
// 假设左子树的中序遍历的长度是 ll，则在前序遍历中，根节点后面的 ll 个数，是左子树的前序遍历，剩下的数是右子树的前序遍历；
// 有了左右子树的前序遍历和中序遍历，我们可以先递归创建出左右子树，然后再创建根节点；

// 时间复杂度分析：我们在初始化时，用哈希表(unordered_map<int,int>)记录每个值在中序遍历中的位置，这样我们在递归到每个节点时，在中序遍历中查找根节点位置的操作，只需要 O(1)O(1) 的时间。此时，创建每个节点需要的时间是 O(1)O(1)，所以总时间复杂度是 O(n)O(n)。


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
	// 用哈希表记录每个值在中序遍历中的位置，便于后面查找
    unordered_map<int,int> pos;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i ++ )
            pos[inorder[i]] = i;
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }

 	// pl = preorder-left, pr = preorder-right, il = inorder-left, ir = inorder-right
	// pl, pr分别表示当前子树的前序遍历在整个preorder遍历数组中的起止坐标
	// il,ir分别表示当前子树的中序遍历在整个inorder数组中的起止下标
	// 这里的left和right不表示左右子树，表示的是数组中区间的左右端点
    TreeNode* dfs(vector<int>&pre, vector<int>&in, int pl, int pr, int il, int ir)
    {
        if (pl > pr) return NULL;
        // k是当前子树的根在中序遍历中的左子树长度
        int k = pos[pre[pl]] - il;
        TreeNode* root = new TreeNode(pre[pl]);
        root->left = dfs(pre, in, pl + 1, pl + k, il, il + k - 1);
        root->right = dfs(pre, in, pl + k + 1, pr, il + k + 1, ir);
        return root;
    }
};
