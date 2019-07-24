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
    vector<int> inorderTraversal(TreeNode* root) {
    	// 94. 二叉树的中序遍历
    	// REF: http://blog.csdn.net/u012162613/article/details/41114105

        //Recursive 递归, 从上而下，假设已经知道小的的结果，利用系统栈,一个套一个的俄罗斯套娃，占用内存多

    	
        vector<int> result, left, right;
        if(!root) return result;

        left = inorderTraversal(root->left);
        for(auto iter = left.begin();iter!=left.end();++iter) result.push_back(*iter);

        result.push_back(root->val);

    	right = inorderTraversal(root->right);
    	for(auto iter = right.begin();iter!=right.end();++iter) result.push_back(*iter);

    	return result;
    }
};


```
非递归做法：用栈模拟

中序序列为左根右，因此用栈模拟这一过程，就是从当前子树根结点出发，一直往左走，把沿途结点全部入栈，直到最左边，对于最左边的结点来说，他没有左孩子，根据“左根右”的顺序，这时需要从堆栈中弹出这个结点，访问它（这里表现为加到res数组中）如果它有右孩子，就往右边走，然后对于这棵子树重复上面的操作。

算法复杂度：每个结点都会入栈一次，出栈一次，因此是O(n).
```

class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		// 94. 二叉树的中序遍历
    	// REF: http://blog.csdn.net/u012162613/article/details/41114105

        //Iterative 迭代，一个连一个的串珠，用循环代替系统栈

        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* p=root;
        if(!root) return result;

        while(p!=nullptr||!stk.empty()){
        	if(p){
        		stk.push(p);
        		p=p->left;
        	}
        	else{
        		p=stk.top();
        		stk.pop();
        		result.push_back(p->val);
        		p=p->right;
        	}
        }
        return result;
	}
};
