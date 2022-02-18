func removeKdigits(num string, k int) string {
    var ans string;
    // fmt.Print(len(num));
    for i:=0;i<len(num);i++ {
        
        for len(ans)>0 && k>0 && ans[len(ans)-1]>num[i]{
            ans=ans[:len(ans)-1];
            k--;
        }

        if len(ans)>0 || num[i]>'0'{
            ans=ans+string(num[i]);
        }
    }
    for len(ans)>0 && k>0{
        ans=ans[:len(ans)-1];
        k--;
    }
    
    if len(ans)==0{
        return "0";
    }
    return ans;
}