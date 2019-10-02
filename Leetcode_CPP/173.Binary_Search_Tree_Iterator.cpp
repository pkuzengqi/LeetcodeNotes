
// LeetCode 173. Binary Search Tree Iterator
// BST 二叉查找树， 查找插入都是O(logn)


// 题目描述
// 实现一个遍历二叉查找树的迭代器（用根结点初始化）。
// 调用next()方法将返回二叉查找树中的一个后继。
// next()方法和hasNext()方法的时间复杂度为均摊O(1)，空间复杂度为O(h)。


// // 思路：栈
// 1. 用栈来模拟BST的中序遍历过程，当前结点进栈，代表它的左子树正在被访问。栈顶结点代表当前访问到的结点。
// 2. 求后继时，只需要弹出栈顶结点，取出它的值。然后将它的右儿子以及右儿子的左儿子等一系列结点进栈，这一步代表找右子树中的最左子结点，并记录路径上的所有结点。
// 3. 判断是否还存在后继只需要判断栈是否为空即可，因为栈顶结点是下一次即将被访问到的结点。



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
      TreeNode* p=root;
      while(p){
        st.push(p);
        p=p->left;
      }
    }
    
    /** @return the next smallest number */
    int next() {
      TreeNode* cur=st.top();
      st.pop();
      int res=cur->val;
      cur=cur->right;
      while(cur){
        st.push(cur);
        cur=cur->left;
      }
      return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */