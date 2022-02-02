class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n=s.size(),m=p.size();
        vector<vector<int>> f(n+1,vector<int>(26));
        vector<int> req(26);
        for(auto i:p) req[i-'a']++;
        for(int i=0;i<n;i++){
            if(i)   f[i]=f[i-1];
            f[i][s[i]-'a']++;
            if(i+1>=m){
                bool ok=1;
                for(int j=0;j<26;j++){
                    if(f[i][j]-(i+1>m?f[i-m][j]:0)!=req[j]){
                        ok=0;
                        break;
                    }
                }
                if(ok) ans.push_back(i-m+1);
            }
        }
        return ans;
    }
};