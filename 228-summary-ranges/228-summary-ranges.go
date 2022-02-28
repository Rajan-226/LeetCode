func summaryRanges(nums []int) []string {
    var ans []string;
    if len(nums)==0{
        return ans;
    }
    
    first:=nums[0];
    for i:=1;i<len(nums);i++{
        if nums[i]!=(nums[i-1]+1){
            if(first!=nums[i-1]){
                ans=append(ans,strconv.Itoa(first)+"->"+strconv.Itoa(nums[i-1]));
            }else{
                ans=append(ans,strconv.Itoa(first));
            }
            first=nums[i];
        }
    }
    if(first!=nums[len(nums)-1]){
        ans=append(ans,strconv.Itoa(first)+"->"+strconv.Itoa(nums[len(nums)-1]));
    }else{
        ans=append(ans,strconv.Itoa(first));
    }
    
    return ans;
}