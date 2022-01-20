class Solution {
public:
    int help(vector<int> &p,int &m){
        int ans=0;
        for(auto& i:p)  ans+=(i+m-1)/m;
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            if(help(piles,mid)<=h) r=mid-1;
            else l=mid+1;
        }
        return r+1;
    }
};