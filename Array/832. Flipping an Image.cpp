class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& a) {
        for(int i=0;i<a.size();i++){
            int j=0,k=a[0].size()-1;
            while(j<k){
                int temp=a[i][j];
                a[i][j]=(a[i][k])^1;
                a[i][k]=temp^1;
                j++;
                k--;
            }
            if(j==k)    a[i][j]^=1;
        }
        return a;
    }
};
