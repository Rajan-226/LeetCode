class Solution {
    public boolean validMountainArray(int[] arr) {
        if(arr.length<3)    return false;
        if(arr[0]>=arr[1])  return false;
        boolean ok=true;
        for(int i=1;i<arr.length;i++){
            if(ok){
                if(arr[i-1]==arr[i]){
                    return false;
                }else if(arr[i-1]>arr[i]){
                    ok=false;
                }
            }
            else{
                if(arr[i]>=arr[i-1])    return false;
            }
        }
        return !ok;
    }
}