class Solution {
public:
    char slowestKey(vector<int>& a, string s) {
        char ans;
        long long mx=0;
        mx=a[0];
        ans=s[0];
        for(int i=1;i<(int)a.size();i++){
            if(a[i]-a[i-1]>=mx){
                if(mx==a[i]-a[i-1]) ans=max(ans,s[i]);
                else    ans=s[i];
                mx=a[i]-a[i-1];
            }
        }
        return ans;
    }
};
