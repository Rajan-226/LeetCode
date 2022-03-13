func isValid(s string) bool {
    arr:=make([]rune,0)
    for _,ch:=range s{
        if ch==')'||ch==']'||ch=='}'{
            if len(arr)==0 || ch!=arr[len(arr)-1]{
                return false
            }
            arr=arr[:len(arr)-1]
        }else if ch=='('{
            arr=append(arr,')')            
        }else if ch=='{'{
            arr=append(arr,'}')
        }else{
            arr=append(arr,']');
        }
    }
    return len(arr)==0;
}