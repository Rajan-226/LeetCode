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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return NULL;
        
        ListNode *cur = head;
        int len = 1;        
        
        while (cur->next) 
            len++,
            cur = cur->next;
        
        cur->next = head;
        
        k = k % len;
        int m = len - k - 1;
        
        while (m--)
            head = head->next;
        
        auto newHead = head->next;
        head->next = NULL;
        
        return newHead;
    }
};