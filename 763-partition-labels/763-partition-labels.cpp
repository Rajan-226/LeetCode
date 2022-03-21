class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]=i;
        int l=0,r=0;
        for(int i=0;i<s.size();i++){
            r=max(mp[s[i]],r);
            if(r==i){
                ans.push_back(r-l+1);
                l=i+1;
            }
        }
        if(l!=s.size())
            ans.push_back(s.size()-l+1);
        return ans;
    }
};