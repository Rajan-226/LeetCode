class Solution {
public:
    #define F first
    #define S second
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<pair<int,int>> v;
        v.push_back({0,0});
        for(int i=0;i<n;i++)    v.push_back({ages[i],scores[i]});
        sort(v.begin(),v.end());
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=1;i<=n;i++){
            int temp=0;
            for(int j=i-1;j>=0;j--){
                if(v[j].S<=v[i].S){
                    temp=max(temp,dp[j][1]+v[i].S);
                }
                
            }
            dp[i][1]=temp;
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        }
        return max(dp[n][0],dp[n][1]);
    }
};
