class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        int n=gas.size();
        int ansIndex=0,csum=0,gsum=0;
        for(int i=0;i<n;i++){
            if(sum<0){
                sum=0;
                ansIndex=i;
            }
            csum+=cost[i];
            gsum+=gas[i];
            sum+=(gas[i]-cost[i]);
        }
        if(csum>gsum)
            return -1;
        return ansIndex;
    }
};