class Solution {
public:
    int calculate(string s) {
        s+='+';
        stack<int> num;
        int cur=0,i=0;
        char last='+';
        while(i<s.size()){
            while(i<s.size()&&(isdigit(s[i])||s[i]==' ')){   
                if(s[i]==' ')       i++;
                else        cur=cur*10+(s[i++]-'0');
            }
            if(last=='*'||last=='/'){
                int lastNum=num.top();
                num.pop();
                if(last=='*')   num.push(cur*lastNum);
                else    num.push(lastNum/cur);
            }
            else{
                if(last=='-')   num.push(-cur);
                else num.push(cur);
            }
            last=s[i];
            i++;
            cur=0;
        }
        int ans=0;
        while(!num.empty()){
            ans+=num.top();
            num.pop();
        }
        return ans;
    }
};
