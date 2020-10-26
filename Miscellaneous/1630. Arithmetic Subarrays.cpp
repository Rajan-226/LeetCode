class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& le, vector<int>& re) {
        int m=re.size();
        int n=nums.size();
        vector<bool> ans(m,1);
        for(int ii=0;ii<m;ii++){
            int l=le[ii],r=re[ii];
            if(l==r||r==l+1){
                continue;
            }
            vector<int> v;
            for(int i=l;i<=r;i++){
                v.push_back(nums[i]);
            }
            sort(v.begin(),v.end());
            int dif=v[1]-v[0];
            for(int i=2;i<v.size();i++){
                if(v[i]-v[i-1]!=dif){
                    ans[ii]=0;
                    break;
                }
            }
        }
        return ans;
    }
};
