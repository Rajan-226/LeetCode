class Solution {
    public int findComplement(int num) {
        int ans=0,cur=1;
        while(num!=1){
            if(num%2==0)
                ans+=cur;
            cur*=2;
            num=(int)Math.floor(num/2);
        }
        return ans;
    }
}