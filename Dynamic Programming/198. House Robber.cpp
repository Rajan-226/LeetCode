class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())    return 0;
        int odd=0,even=0;
        for(int i=0;i<(int)nums.size();i++){
            if(i%2) odd=max(even,odd+nums[i]);
            else    even=max(odd,even+nums[i]);
        }
        return max(odd,even);
    }
};
