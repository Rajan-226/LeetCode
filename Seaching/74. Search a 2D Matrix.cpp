class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())  return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        int col=0,row=n-1;
        while(col<m&&row>=0){
            if(matrix[row][col]==target)    return 1;
            if(matrix[row][col]<target) col++;
            else    row--;
        }
        return 0;
    }
};
