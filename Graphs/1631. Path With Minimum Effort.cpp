class Solution {
public:
    #define F first
    #define S second
    #define ll long long
    bool isvalid(int x,int y,int n,int m){
        return x>=0&&y>=0&&x<n&&y<m;
    }
    int minimumEffortPath(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        int dx[4]={-1,1,0,0};   
        int dy[4]={0,0,-1,1};
        priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>> q;
        vector<vector<int>> dis(n+5,vector<int>(m+4,INT_MAX));
        vector<vector<bool>> vis(n+5,vector<bool>(m+4,0));
        
        q.push({0,{0,0}});
        dis[0][0]=0;
        
        while(!q.empty()){
            pair<ll,pair<int,int>> p=q.top();
            int x=p.S.F,y=p.S.S;
            int dif=p.F;
            q.pop();
            if(vis[x][y])    continue;
            vis[x][y]=1;

            for(int i=0;i<4;i++){
                if(isvalid(x+dx[i],y+dy[i],n,m)){
                    int curx=x+dx[i];
                    int cury=y+dy[i];
                    
                    if(dis[curx][cury]>max(dis[x][y],abs(a[x][y]-a[curx][cury]))){
                        
                        dis[curx][cury]=max(dis[x][y],abs(a[x][y]-a[curx][cury]));
                        q.push({dis[curx][cury],{curx,cury}});
                        
                    }
                }

            }
        }
        return dis[n-1][m-1];
    }
};
