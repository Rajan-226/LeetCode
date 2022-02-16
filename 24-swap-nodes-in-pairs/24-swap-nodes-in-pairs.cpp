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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* nxt=dummy;
        dummy->next=head;
        while(head&&head->next){
            ListNode* temp=(head->next)->next;
            nxt=nxt->next=head->next;
            nxt=nxt->next=head;
            nxt->next=temp;
            head= nxt->next;
        }
        return dummy->next;
    }
};