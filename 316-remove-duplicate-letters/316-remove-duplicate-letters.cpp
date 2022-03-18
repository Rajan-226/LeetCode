class Solution {
public:
    bool isOn(char c,int x){
        return (1<<(c-'a'))&x;
    }
    int turnOff(char c,int x){
        return (1<<(c-'a'))^x;
    }
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int> freq(n+1);
        for(int i=n-1;i>=0;i--){
            freq[i]=freq[i+1]|(1<<(s[i]-'a'));
        }
        string ans="";
        int cur=0;
        for(int i=0;i<n;i++){
            if(isOn(s[i],cur)) continue;
            
            while(!ans.empty()&&s[i]<ans.back()&&isOn(ans.back(),freq[i+1])){
                cur=turnOff(ans.back(),cur);
                ans.pop_back();
            }
            
            ans.push_back(s[i]);
            cur=cur|(1<<(s[i]-'a'));
        }
        return ans;
    }
};