class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            int j=i;
            while(i+1<nums.size()&&nums[i+1]==nums[i]+1){
                i++;
            }
            if(j==i)    ans.push_back(to_string(nums[i]));
            else        ans.push_back(to_string(nums[j])+"->"+to_string(nums[i]));
        }
        return ans;
    }
};
