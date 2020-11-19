class Solution {
public:
    string rep(int n,string s){
        string ans="";
        while(n--)  ans+=s;
        return ans;
    }
    
    string help(int i,string& s){
        if(i==s.size()||s[i]==']') return "";
        
        if(s[i]>='0'&&s[i]<='9'){
            int num=0;
            while(s[i]>='0'&&s[i]<='9'){
                num=num*10+s[i]-'0';
                i++;
            }
            
            int j=i+1,c=1;
            while(c){
                if(s[j]==']')   c--;
                if(s[j]=='[')   c++;
                j++;
            }
            return rep(num,help(i+1,s))+help(j,s);
        }
        return s[i]+help(i+1,s);
    }
    
    string decodeString(string s) {
        return help(0,s);
    }
};
