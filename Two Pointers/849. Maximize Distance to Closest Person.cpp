class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=0;
        int n=seats.size();
        int i=0,j=n-1;
        while(i<=j&&seats[i]==0){
            i++;
        }
        ans=i;
        while(j>=i&&seats[j]==0){
            j--;
        }
        ans=max(ans,n-j-1);
        while(i<j){
            while(i<j&&seats[i]==1){
                i++;
            }
            int c=0;
            while(i<j&&seats[i]==0){
                i++;
                c++;
            }
            ans=max(ans,(int)ceil(1.0*c/2));
        }
        return ans;
    }
};
