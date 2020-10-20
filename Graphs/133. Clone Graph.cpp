class Solution {
public:
    unordered_map<Node* ,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node)   return NULL;
        if(mp.find(node)==mp.end()){
            mp[node]=new Node(node->val,{});
            for(Node* child : node->neighbors ){
                mp[node]->neighbors.push_back(cloneGraph(child));
            }
        }
        return mp[node];
    }
};
