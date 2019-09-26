// 二叉树的序列化和反序列化
// 序列化就是dfs实现中序遍历
// 反序列化

// 注意双引号和单引号

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs1(root, res); //传参不用额外标注引用
        return res;
    }

    void dfs1(TreeNode* root, string& res)
    {
        if (!root)
        {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ',';
        dfs1(root->left, res);
        dfs1(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs2(data, u);
    }

    TreeNode* dfs2(string &data, int &u)
    {
        if (data[u] == '#')
        {
            u += 2;
            return NULL;
        }

        int t = 0;
        bool is_minus = false;
        while (data[u] != ',')
        {
            if (data[u] == '-') is_minus = true;
            else t = t * 10 + data[u] - '0';
            u ++ ;
        }
        u ++ ; // note
        if (is_minus) t = -t;

        auto root = new TreeNode(t); //记得写new
        root->left = dfs2(data, u);
        root->right = dfs2(data, u);

        return root;
    }
};

