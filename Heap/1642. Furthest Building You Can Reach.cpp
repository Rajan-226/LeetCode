class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=1;i<heights.size();i++){
            if(heights[i]>heights[i-1]){
                q.push(heights[i]-heights[i-1]);
                if(ladders==0){
                    if(q.top()>bricks)  return i-1;
                    bricks-=q.top();
                    q.pop();
                }
                else{
                    ladders--;
                }
            }
        }
        return (int)heights.size()-1;
    }
};
