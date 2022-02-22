func titleToNumber(a string) int {
    ans:=0;
    for i:=0;i<len(a);i++{
        ans=ans*26+int(a[i]-'A'+1);
    }
    return ans;
}