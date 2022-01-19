/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function(head) {
    var slow=head;
    var fast=head;
    while(fast!=null&&fast.next!=null){
        slow=slow.next;
        fast=fast.next.next;
        if(fast==slow)
            break;
    }
    if(fast==null||fast.next==null){
        return null;
    }
    var meetingPosition=fast;
    var front=head;
    while(front!=meetingPosition){
        front=front.next;
        meetingPosition=meetingPosition.next;
    }
    return front;
};