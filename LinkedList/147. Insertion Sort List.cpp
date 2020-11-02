/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)   return head;
        ListNode* ans=new ListNode(0);
        ListNode *prev,*nxt,*temp;
        while(head){
            prev=ans;
            nxt=ans->next;
            while(nxt&&(nxt->val)<(head->val)){
                nxt=nxt->next;
                prev=prev->next;
            }
            temp=head->next;
            prev->next=head;
            prev=prev->next;
            prev->next=nxt;
            head=temp;
        }
        return ans->next;
    }
};
