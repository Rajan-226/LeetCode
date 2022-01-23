class Solution {
public:
    void rec(int digit,int num,int l,int h,vector<int>& ans){
        if(num>=l&&num<=h){
            ans.push_back(num);
        }
        if(num>h||digit==9)
            return ;
        rec(digit+1,num*10+digit+1,l,h,ans);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            rec(i,i,low,high,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};