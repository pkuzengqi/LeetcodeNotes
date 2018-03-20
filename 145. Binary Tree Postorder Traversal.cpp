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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result,left,right;
        if(!root) return result;

        left = postorderTraversal(root->left);
        for(auto iter=left.begin();iter!=left.end();++iter) result.push_back(*iter);

        right = postorderTraversal(root->right);
    	for(auto iter = right.begin();iter!=right.end();++iter) result.push_back(*iter);

    	result.push_back(root->val);

    	return result;
    }
};

class Solution{
public:
	vector<int> postorderTraversal(TreeNode* root){
		//REF: http://blog.csdn.net/crazy1235/article/details/51494797
		vector<int> result;
		stack<TreeNode*> stk;
		TreeNode* p=root;
		if(!root)return result;

		while(p!=nullptr || !stk.empty()){
			if(p){
				stk.push(p);
				if(p->right!=nullptr) stk.push(p->right);
				p=p->left;
			}
			else{
				while(!stk.empty()&&((p==stk.top()->left || p==stk.top()->right){
					p = stk.top();
					stk.pop();
					result.push_back(p->val);
				}
				if(!stk.empty()){
					p = stk.top();
					stk.pop();
				}
			}
		}
		return result;
	}
};