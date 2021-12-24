class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto &interval:intervals){
            if(ans.empty()||interval[0]>ans.back()[1]){
                ans.push_back(interval);
            }
            else if(interval[1]>ans.back()[1]){
                ans.back()[1]=interval[1];
            }
        }
        return ans;
    }
};