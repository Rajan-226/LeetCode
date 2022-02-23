/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int,Node*> mp;
    Node* help(Node* root){
        if(mp[root->val])    return mp[root->val];
        
        Node* now = new Node(root->val);
        mp[root->val]=now;
        
        for(auto child:root->neighbors){
            now->neighbors.push_back(help(child));
        }
        
        return now;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        mp.clear();
        return help(node);
    }
};