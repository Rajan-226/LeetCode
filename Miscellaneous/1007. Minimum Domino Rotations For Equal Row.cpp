class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int ans=n+1;
        for(int num=1;num<=6;num++){
            bool ok1=1,ok2=1;
            int c1=n,c2=n;
            for(int i=0;i<A.size();i++){
                if(A[i]==num)   c1--;
                else if(B[i]!=num)  ok1=0;
                if(B[i]==num)   c2--;
                else if(A[i]!=num)  ok2=0;
                if(!ok1&&!ok2)  break;
            }
            if(ok1) ans=min(ans,c1);
            if(ok2) ans=min(ans,c2);
        }
        if(ans==n+1)    return -1;
        return ans;
    }
};
