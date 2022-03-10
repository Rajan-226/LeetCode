/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    ans:= l1
    carry:=0
    
    var prev *ListNode=nil;
    for l1!=nil && l2!=nil{
        now:=l1.Val+l2.Val+carry
        l1.Val=now%10
        carry=now/10
        
        prev=l1
        l1=l1.Next
        l2=l2.Next
    }
    
    for l2!=nil{
        prev.Next=l2
        prev=prev.Next
        now:=carry+l2.Val
        prev.Val=now%10
        carry=now/10
        l2=l2.Next
    }
    for l1!=nil{
        prev.Next=l1
        prev=prev.Next
        now:=carry+l1.Val
        prev.Val=now%10
        carry=now/10
        l1=l1.Next
    }
    if carry>0{
        prev.Next=&ListNode{carry, nil}
    }
    
    return ans
}
func reverse(head *ListNode) *ListNode{
    var prev *ListNode=nil
    for head!=nil{
        temp:=head.Next
        head.Next=prev
        prev=head
        head=temp
    }
    return prev;
}