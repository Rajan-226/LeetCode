class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        vector<string> ans;
        string temp;
        for(int i=0;i+9<s.size();i++){
            temp=s.substr(i,10);
            mp[temp]++;
            if(mp[temp]==2) ans.push_back(temp);
        }
        return ans;
    }
};
