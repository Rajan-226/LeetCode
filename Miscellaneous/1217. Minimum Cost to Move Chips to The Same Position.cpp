class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        if(pos.size()==1)    return 0;
        int ans1=0,ans2=0;
        for(int i=0;i<pos.size();i++){
            if(pos[i]%2) ans1++;
            else    ans2++;
        }
        return min(ans1,ans2);
    }
};
