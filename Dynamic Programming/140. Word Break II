class Solution
{
public:
    void help(vector<string> &ans, vector<vector<string>> &dp, int ind, string temp)
    {
        if (ind == 0)
        {
            temp.pop_back();
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        for (auto s : dp[ind])
        {
            int k = s.size();
            reverse(s.begin(), s.end());
            help(ans, dp, ind - k, temp + s + " ");
        }
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        int m = wordDict.size();
        vector<vector<string>> dp(n + 1);
        dp[0].push_back("AC");
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int k = wordDict[j].size();

                if (i < k || dp[i - k].empty())
                    continue;

                bool ok = 1;
                for (int ind = 0; ind < k; ind++)
                {
                    if (wordDict[j][k - ind - 1] != s[i - ind - 1])
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                    dp[i].push_back(wordDict[j]);
            }
        }
        vector<string> ans;
        help(ans, dp, n, "");
        return ans;
    }
};
