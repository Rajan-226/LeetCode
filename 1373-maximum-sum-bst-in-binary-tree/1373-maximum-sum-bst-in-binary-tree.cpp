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
    vector<int> help(TreeNode* root,int &ans){
        int isBalanced=1;
        int sum=root->val;
        int nin=root->val;
        int nax=root->val;
        if(root->left){
            auto left=help(root->left,ans);
            isBalanced=isBalanced && left[0];
            isBalanced=isBalanced&&((root->val)>left[2]);
            nin=min(nin,left[1]);
            nax=max(nax,left[2]);
            sum+=left[3];
        }
        if(root->right){
            auto right=help(root->right,ans);
            isBalanced=isBalanced&&right[0];
            isBalanced=isBalanced&&((root->val)<right[1]);
            
            nin=min(nin,right[1]);
            nax=max(nax,right[2]);
            sum+=right[3];
        }
        if(!isBalanced) sum=0;
        ans=max(ans,sum);
        return {isBalanced,nin,nax,sum};
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        help(root,ans);
        return ans;
    }
};