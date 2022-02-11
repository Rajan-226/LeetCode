class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return 0;
        vector<int> f(26);
        for(auto i:s1) f[i-'a']++;
        vector<int> temp(26);
        for(int i=0;i<s1.size();i++) temp[s2[i]-'a']++;
        if(temp==f) return 1;
        for(int i=s1.size();i<s2.size();i++){
            temp[s2[i-s1.size()]-'a']--;
            temp[s2[i]-'a']++;
            if(temp==f) return 1;
        }
        return 0;
    }
};