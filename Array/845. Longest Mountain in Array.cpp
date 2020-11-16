class Solution {
public:
    int longestMountain(vector<int>& a) {
        int ans=0;
        int i=0,n=a.size();
        while(i<n-1){
            while(i<n-1&&a[i]>=a[i+1])  i++;
            int c=0;
            while(i<n-1&&a[i]<a[i+1]){
                c++;
                i++;
            }
            if(i==n-1)  break;
            if(a[i+1]==a[i])    continue;
            while(i<n-1&&a[i]>a[i+1]){
                c++;
                i++;
            }
            ans=max(ans,c+1);
        }
        return ans;
    }
};
