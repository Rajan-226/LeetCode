class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int ans=INT_MAX,nin=INT_MAX;
        for(auto i:nums){
            if(i%2) i*=2;
            q.push(i);  nin=min(nin,i);
        }
        while(q.top()%2==0){
            int val=q.top();
            ans=min(ans,val-nin);
            nin=min(nin,val/2);
            q.pop();q.push(val/2);
        }
        
        return min(ans,q.top()-nin);
    }
};