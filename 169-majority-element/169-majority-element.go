func majorityElement(nums []int) int {
    cnt:=1
    element:=nums[0]
    for i:=1;i<len(nums);i++{
        if nums[i] == element{
            cnt++
        } else {
            cnt--
        }
        
        if cnt == 0{
            element=nums[i];
            cnt=1;
        }
    }
    return element
}