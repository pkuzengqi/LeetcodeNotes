/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<int,Node*> hash;
  
    Node* cloneGraph(Node* node) {
      if(!node) return 0;
      auto root = new Node(node->val, vector<Node*>());
      hash[node->val] = root;
      dfs(node);
      return root;
    }
  
    void dfs(Node* node){
      for(auto &neighbor:node->neighbors){
        if(!hash.count(neighbor->val)){
          hash[neighbor->val] = new Node(neighbor->val, vector<Node*>());
          dfs(neighbor);
        }
        hash[node->val]->neighbors.push_back(hash[neighbor->val]);
      }
    }
};