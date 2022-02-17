class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void help(int index,vector<int> &arr,int req){
        if(req<=0){
            if(req==0) ans.push_back(temp);
            return ;
        }
        for(int i=index;i<arr.size();i++){
            temp.push_back(arr[i]);
            help(i,arr,req-arr[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        help(0,candidates,target);
        return ans;
    }
};