class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n=ast.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(ans.empty()||ast[i]>0){
                ans.push_back(ast[i]);
            }
            else{
                while(!ans.empty()&&ans.back()<abs(ast[i])&&ans.back()>0){
                    ans.pop_back();
                }
                if(ans.empty())   ans.push_back(ast[i]);
                else if(ans.back()==abs(ast[i]))  ans.pop_back();
                else if(ans.back()<0)   ans.push_back(ast[i]);
            }   
        }
        return ans;
    }
};
