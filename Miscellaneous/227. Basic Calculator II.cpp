class Solution {
public:
    void help(string& s){
        int n=0;
        char lastSign='+';
        while(n<s.size()){
            while(n<s.size()&&(isdigit(s[n])||s[n]==' '))   n++;
            
            if(n<s.size()&&(s[n]=='*'||s[n]=='/')){
                char c=s[n];
                string a,b;
                int i=n+1;
                while(i<s.size()&&(isdigit(s[i])||s[i]==' ')){
                    if(s[i]!=' ')       a+=s[i++];
                    else i++;
                }
                n--;
                while(n>=0&&(isdigit(s[n])||s[n]==' ')){
                    if(s[n]!=' ')   b+=s[n--];
                    else            n--;
                }
                reverse(b.begin(),b.end());
                int val;
                if(c=='/')           val=stoi(b)/stoi(a);
                else if(c=='*')      val=stoi(b)*stoi(a);
                s.erase(n+1,i-n-1);
                s=s.substr(0,n+1)+to_string(val)+s.substr(n+1);
            }
            else lastSign=s[n];
            n++;
        }
    }
    int calculate(string s) {
        help(s);
        string last;
        int i=0;
        while(i<s.size()&&(isdigit(s[i])||s[i]==' ')){
            if(s[i]!=' ')       last+=s[i++];
            else i++;
        }
        while(i<s.size()){
            char c=s[i];
            i++;
            string now;
            while(i<s.size()&&(isdigit(s[i])||s[i]==' ')){
                if(s[i]!=' ')       now+=s[i++];
                else i++;
            }
            int val;
            if(c=='+')  val=stoi(last)+stoi(now);
            else if(c=='-') val=stoi(last)-stoi(now);
            last=to_string(val);
        }
        
        return stoi(last);
    }
};
