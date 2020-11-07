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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a,b;
        while(l1){
            a.push_back(l1->val);
            l1=l1->next;
        }
        while(l2){
            b.push_back(l2->val);
            l2=l2->next;
        }
        if(a.size()<b.size())   swap(a,b);
        vector<int> ans;
        int carry=0,j=b.size()-1;
        for(int i=a.size()-1;i>=0;i--){
            if(j>=0){
                ans.push_back((a[i]+b[j]+carry)%10);
                carry=(a[i]+b[j]+carry)/10;
                j--;
            }
            else{
                ans.push_back((a[i]+carry)%10);
                carry=(a[i]+carry)/10;
            }
        }
        if(carry)   ans.push_back(carry);
        ListNode* head=new ListNode();
        ListNode* temp=head;
        for(int i=ans.size()-1;i>=0;i--){
            temp->next=new ListNode(ans[i]);
            temp=temp->next;
        }
        return head->next;
    }
};
