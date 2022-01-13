class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())  return 0;
        sort(points.begin(),points.end(),comp);
        int ans=1;
        int last=points[0][1];
        for(int i=1;i<(int)points.size();i++){
            if(points[i][0]>last){
                ans++;
                last=points[i][1];
            }
        }
        return ans;
    }
};