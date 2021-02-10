
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return head;    
        Node* temp=head;
        while(temp){
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            if(temp->random)  temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        temp=head;
        Node* list=temp->next;
        Node* dummy=list;
        while(temp){
            temp=temp->next=temp->next->next;
            if(temp)    dummy=dummy->next=temp->next;
        }
        return list;
    }
};
