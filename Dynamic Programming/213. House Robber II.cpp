class Solution {
public:
    int help(vector<int>& nums,int ind){
        int n=nums.size()-ind;
        int odd=0,even=0;
        for(int i=ind^1;i<n;i++){
            if(i%2) odd=max(even,odd+nums[i]);
            else    even=max(odd,even+nums[i]);
        }
        return max(odd,even);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)    return nums[0];
        return max(help(nums,0),help(nums,1));
    }
};
