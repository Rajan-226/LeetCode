/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if(root==null)
            return root;
        Queue<Node> q=new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int sz=q.size();
            
            Node last=q.peek();
            q.remove();
            
            if(last.left!=null){
                q.add(last.left);
                q.add(last.right);
            }
            
            for(int i=1;i<sz;i++){
                Node cur=q.peek();
                q.remove();
                
                if(cur.left!=null){
                    q.add(cur.left);
                    q.add(cur.right);
                } 
                
                last=last.next=cur;
            }
        }
        return root;
    }
}