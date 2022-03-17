class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1||k==0){
            return k%2==1?-1:nums[0];
        }
        if(k==1) return nums[1];
        if(k==2) return max(nums[0],n>=3?nums[2]:-1);
        int ans=0;
        for(int i=0;i<min(n,k+1);i++){
            if(i!=(k-1))
                ans=max(ans,nums[i]);
        }
        return ans;
    }
};