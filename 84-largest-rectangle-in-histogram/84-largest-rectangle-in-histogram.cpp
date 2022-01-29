class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;   
        heights.push_back(0);   //as any number in the stack will be greater than 0
        int ans=0;
        for(int i=0;i<heights.size();i++){
            while(!s.empty()&&heights[s.top()]>=heights[i]){
                int x=s.top();
                s.pop();
                int l=s.empty()?-1:s.top();
                ans=max(ans,(i-l-1)*heights[x]);    //We are not including i and l here in
            }
            s.push(i);
        }
        return ans;
        
    }
};