class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int ans=0;
        for(int i=0;i<a.size();i++){
            int sum=0;
            for(int j=0;j<a[0].size();j++)  sum+=a[i][j];
            ans=max(ans,sum);
        }
        return ans;
    }
};