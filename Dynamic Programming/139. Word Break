class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        int m = wordDict.size();
        vector<bool> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            //let's check whether there is any word in dictionary
            //which can be appended to some previous valid prefix string
            //and make this prefix string valid
            for (int j = 0; j < m; j++)
            {
                int k = wordDict[j].size();

                if (i < k || !dp[i - k])
                    continue;

                bool ok = 1;
                for (int ind = 0; ind < k; ind++)
                {
                    if (wordDict[j][k - ind - 1] != s[i - ind - 1]) //trasversing the words from behind
                    {
                        ok = 0; //If there is any dis-simialrity,then break
                        break; 
                    }
                }
                dp[i] = ok;
                if (ok)
                    break;
            }
        }
        return dp[n];
    }
};
