class Solution {
public:
    int check(int i, vector<int>& a,int sz){
        if(a[i]==1) return 0;
        int now=0;
        if(i==0||a[i-1]==0) now++;
        if(i==(sz-1)||a[i+1]==0)    now++;
        if(now==2)  a[i]=1;
        return a[i];
    }
    bool canPlaceFlowers(vector<int>& a, int n) {
        int sz=a.size();
        for(int i=0;i<sz;i++){
            n-=check(i,a,sz);
        }
        return n<=0;
    }
};