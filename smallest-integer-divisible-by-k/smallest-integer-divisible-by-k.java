class Solution {
    public int smallestRepunitDivByK(int k) {
        if(k%2==0)
            return -1;
        int ans=1,rem=0;
        int num=1;
        HashSet<Integer> mp=new HashSet<>();
        while(true){
            rem=(rem+num)%k;
            if(rem==0)
                return ans;
            if(mp.contains(rem))
                break;
            
            mp.add(rem);
            num=(num*10)%k;
            ans++;
        }
        
        return -1;
    }
}