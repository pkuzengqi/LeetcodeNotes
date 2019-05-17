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