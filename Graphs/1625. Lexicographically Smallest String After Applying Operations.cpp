class Solution {
public:
    unordered_map<string,bool> mp;
    string ans;
    void dfs(string s,int a,int b){
        if(mp[s])   return ;
        ans=min(ans,s);
        mp[s]=1;
        rotate(s.begin(),s.begin()+s.size()-b,s.end());
        dfs(s,a,b);
        for(int j=1;j<s.size();j+=2)        s[j]='0'+(s[j]-'0'+a)%10;
        dfs(s,a,b);
    }
    string findLexSmallestString(string s, int a, int b) {
        ans=s;
        dfs(s,a,b);
        return ans;
    }
};
