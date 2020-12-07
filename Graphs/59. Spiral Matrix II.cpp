class Solution {
public:
    vector<vector<int>> ans;
    int N;
    bool isvalid(int x,int y){
        return x>=0&&y>=0&&x<N&&y<N&&(ans[x][y]==0);
    }
    // r d l u
    void help(int c,int x,int y,bool up){
        ans[x][y]=c;
        c++;
        if(up&&isvalid(x-1,y)){
            help(c,x-1,y,1);
        }
        else if(isvalid(x,y+1)){
            help(c,x,y+1,0);
        }
        else if(isvalid(x+1,y)){
            help(c,x+1,y,0);
        }
        else if(isvalid(x,y-1)){
            help(c,x,y-1,0);
        }
        else if(isvalid(x-1,y)){
            help(c,x-1,y,1);
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        ans=vector<vector<int>>(n,vector<int>(n,0));
        N=n;
        help(1,0,0,0);
        return ans;
    }
};
