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
    ListNode* sortList(ListNode* head) {
        if(head==NULL)  return head;
        vector<int> ans;
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->next;
        }
        sort(ans.begin(),ans.end());
        ListNode *par=new ListNode(ans[0]);
        ListNode *last=par;
        for(int i=1;i<ans.size();i++){
            ListNode *temp=new ListNode(ans[i]);
            last->next=temp;
            last=last->next;
        }
        return par;
    }
};