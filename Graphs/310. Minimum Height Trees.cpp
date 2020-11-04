class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)        return {0};
        
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<n-1;i++){
            int a=edges[i][0],b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            indegree[a]++;
            indegree[b]++;
        }
        int count=n;
        while(count>2){
            vector<int> v;
            for(int i=0;i<n;i++){
                if(indegree[i]==1){
                    count--;
                    indegree[i]=-1;
                    v.push_back(i);
                }
            }
            for(auto& node:v){
                for(auto& child:adj[node])   indegree[child]--;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)    if(indegree[i]>=0)      ans.push_back(i);
        return ans;
    }
};
