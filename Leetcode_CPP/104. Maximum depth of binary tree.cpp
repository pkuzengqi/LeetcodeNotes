// 104 Maximum depth of binary tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<stack>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        stack<TreeNode*> nodes ;
        stack<int> depths ;


       	nodes.push(root);
       	depths.push(0);

       	while(!nodes.empty()){
       		TreeNode* current_node = nodes.pop();
       		int current_depth = depths.pop();

       		if(current_node->val==NULL){
       			max_depth = max(max_depth,current_depth);
       		}
       		else{
       			++current_depth;
       			nodes.push(current_node->left);
       			depths.push(current_depth);
       			nodes.push(current_node->right);
       			depths.push(current_depth);
       		}
       	}

       	return max_depth;
    }
};



