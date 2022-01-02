class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] freq=new int[60];
        int ans=0;
        for(int i=0;i<time.length;i++){
            int req=(60-time[i]%60)%60;
            ans+=freq[req];
            freq[time[i]%60]++;
        }
        return ans;
    }
}