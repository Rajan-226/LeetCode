class Solution {
public:
    bool detectCapitalUse(string word) {
        bool ok=1;
        for(auto i:word){   
            if(i<'A'||i>'Z'){
                ok=0;
                break;
            }
        }
        if(ok)  return true;
        ok=1;
        for(int i=1;i<word.size();i++)
            if(word[i]>='A'&&word[i]<='Z')
                return 0;  
        return 1;
    }
};