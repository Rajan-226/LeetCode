class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int cost) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        int ans=0;
        while(i<=j){
            if(cost>=tokens[i]){
                ans++;
                cost-=tokens[i++];
            }
            else if(i!=j&&ans){
                ans--;
                cost+=tokens[j--];
            }
            else    break;
        }
        return ans;
    }
};
