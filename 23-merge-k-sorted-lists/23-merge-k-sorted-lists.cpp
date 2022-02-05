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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode();
        ListNode* temp=head;
        while(l1&&l2){
            int val1=l1->val,val2=l2->val;
            if(val1<val2){
                ListNode* t=new ListNode(val1);
                l1=l1->next;
                temp=temp->next=t;
            }
            else{
                ListNode* t=new ListNode(val2);
                l2=l2->next;
                temp=temp->next=t;
            }
        }
        if(l1)  temp->next=l1;
        if(l2)  temp->next=l2;
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
};