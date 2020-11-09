/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void help(TreeNode* root,int mx,int mn){
        if(!root)   return ;
        ans=max(ans,abs(mx-(root->val)));
        ans=max(ans,abs(mn-root->val));
        mn=min(mn,root->val);
        mx=max(mx,root->val);
        help(root->left,mx,mn);
        help(root->right,mx,mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        help(root,root->val,root->val);
        return ans;
    }
};
