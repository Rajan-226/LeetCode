func countBits(n int) []int {
    var arr=make([]int,n+1)
    for i:=0;i<=n;i++{
        j:=i
        for j>0{
            arr[i]+=j%2
            j/=2;
        }
        
    }
    
    return arr
}