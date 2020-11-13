/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            Node* last=q.front();
            q.pop();
            if(last->left){
                q.push(last->left);
                q.push(last->right);
            }
            for(int i=1;i<sz;i++){
                last->next=q.front();
                last=q.front();
                if(last->left){
                    q.push(last->left);
                    q.push(last->right);
                }
                q.pop();
            }
            last->next=NULL;
        }
        return root;
    }
};
