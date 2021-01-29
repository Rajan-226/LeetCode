class Solution
{
public:
    map<int, vector<pair<int, int>>> mp;
    void help(TreeNode *root, int x, int y)
    {
        if (!root)
            return;
        mp[x].push_back({-y, root->val});
        help(root->left, x - 1, y - 1);
        help(root->right, x + 1, y - 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        mp.clear();
        help(root, 0, 0);
        vector<vector<int>> ans;
        for (auto x : mp)
        {
            sort(x.second.begin(), x.second.end());
            vector<int> temp;
            for (auto p : x.second)
            {
                temp.push_back(p.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
