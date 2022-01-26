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
    int a[100000];
    int i=0,j=0;
    void get(TreeNode* root,bool ok){
        if(root==NULL)  return ;
        
        get(root->left,ok);
        if(ok)
            a[i++]=root->val;
        else
            a[j++]=root->val;
        get(root->right,ok);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        get(root1,1);
        j=i;
        get(root2,0);
        vector<int> v(j);
        
        merge(a, a + i, a + i, a + j, begin(v));
        return v;
    }
};