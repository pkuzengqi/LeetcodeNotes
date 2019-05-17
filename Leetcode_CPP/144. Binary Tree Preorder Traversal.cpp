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
    vector<int> preorderTraversal(TreeNode* root) {
        // 144. 二叉树的前序遍历
        // Recursive

        vector<int> result,left,right;
        if(!root) return result;

        result.push_back(root->val);

        left = preorderTraversal(root->left);
        for(auto iter=left.begin();iter!=left.end();++iter) result.push_back(*iter);

        right = preorderTraversal(root->right);
    	for(auto iter = right.begin();iter!=right.end();++iter) result.push_back(*iter);

    	return result;
    }
};

classs Solution{
public:
	vector<int> preorderTraversal(TreeNode* root){
		vector<int> result;
		stack<TreeNode*> stk;
		TreeNode* p=root;
		if(!root)return result;

		while(p!=nullptr || !stk.empty()){
			if(p){
				result.push_back(p->val);
				
			}
			else{
				p = stk.
			}
		}
	}
}