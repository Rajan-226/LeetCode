/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int ans;
    private int[] help(TreeNode root){
        if(root==null)
            return new int[]{Integer.MAX_VALUE,Integer.MIN_VALUE};
        int[] left=help(root.left);
        int[] right=help(root.right);
        
        left[0]=Math.min(left[0],right[0]);
        left[1]=Math.max(left[1],right[1]);
        
        if(left[0]!=Integer.MAX_VALUE)  ans=Math.max(ans,Math.abs(left[0]-root.val));
        if(left[1]!=Integer.MIN_VALUE)  ans=Math.max(ans,Math.abs(left[1]-root.val));
        
        return new int[]{Math.min(left[0],root.val),Math.max(left[1],root.val)};
    }
    public int maxAncestorDiff(TreeNode root) {
        ans=0;
        help(root);
        return ans;
    }
}