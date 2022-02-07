class Solution {
public:
    char findTheDifference(string s, string t) {
        int x=t[(int)t.size()-1]-'a';
        for(int i=0;i<s.size();i++){
            x^=s[i]-'a';
            x^=t[i]-'a';
        }
        return char('a'+x);
    }
};