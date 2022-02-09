class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i:nums)    mp[i]++;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(k==0)
                ans+=mp[nums[i]+k]>1;
            else
                ans+=mp[nums[i]+k]>=1;
            mp[nums[i]+k]=0;
            
        }
        return ans;
    }
};