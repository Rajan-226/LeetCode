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
    unordered_map<TreeNode*,int> mp[2];
    int help(TreeNode* root,bool ok){
        if(!root)   return 0;
        if(mp[ok][root])    return mp[ok][root];
        int tempa=0,tempb=0;
        tempa+=help(root->left,1);
        tempa+=help(root->right,1);
        if(ok){
            tempb=root->val;
            tempb+=help(root->left,0);
            tempb+=help(root->right,0);
        }
        return mp[ok][root]=max(tempa,tempb);
    }
    int rob(TreeNode* root) {
        mp[0].clear();mp[1].clear();
        return help(root,1);
    }
};
