class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
                              "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--",
                              "--.."};
        unordered_set<string> s;
        for(auto& word:words){
            string crypt="";
            for(auto& ch:word){
                crypt+=v[ch-'a'];
            }
            s.insert(crypt);
        }
        return (int)s.size();
    }
};
