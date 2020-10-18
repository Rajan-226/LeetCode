class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(),0);
        int mx=*max_element(candies.begin(),candies.end());
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=mx)  ans[i]=1;
        }
        return ans;
    }
};
