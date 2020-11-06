class Solution {
public:
    int check(vector<int>&nums,int div){
        int sum=0;
        for(auto& num:nums){
            sum+=ceil(1.0*num/div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1,hi=(int)1e9;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(nums,mid)<=threshold){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return hi+1;
    }
};
