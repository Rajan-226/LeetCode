class Solution {
public:
    #define ll long long
    vector<ll> help(int src,vector<vector<pair<int,int>>>& adj,int n){
        vector<ll> dis(n,(ll)1e15);
        priority_queue<pair<ll,int>> q;
        q.push({0,src});
        while(!q.empty()){
            ll tillNow=-q.top().first;
            int now=q.top().second;
            q.pop();
            if(dis[now]<=tillNow) continue;
            dis[now]=tillNow;
            for(auto p:adj[now]){
                ll next=tillNow+p.second;
                if(dis[p.first]>next)
                    q.push({-next,p.first});
            }
        }
        return dis;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> adj(n),rev(n);
        for(auto p:edges){
            int u=p[0],v=p[1],w=p[2];
            adj[u].push_back({v,w});
            rev[v].push_back({u,w});
        }
        vector<ll> disD=help(dest,rev,n);
        vector<ll> dis1=help(src1,adj,n);
        vector<ll> dis2=help(src2,adj,n);
        ll ans=1e15;
        for(int i=0;i<n;i++){
            ans=min(ans,disD[i]+dis1[i]+dis2[i]);
        }
        if(ans>=(ll)1e12) return -1;
        return ans;
    }
};