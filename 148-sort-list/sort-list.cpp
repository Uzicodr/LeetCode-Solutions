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
    ListNode* findmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* mergeit(ListNode* head1,ListNode* head2){
        ListNode* temp1=head1;
        ListNode* temp2=head2;
        ListNode* dummy=new ListNode(-1,NULL);
        ListNode* head=dummy;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<temp2->val){
                dummy->next=temp1;
                dummy=temp1;
                temp1=temp1->next;
            }
            else{
                dummy->next=temp2;
                dummy=temp2;
                temp2=temp2->next;
            }
        }

        while(temp1!=NULL){
            dummy->next=temp1;
            dummy=temp1;
            temp1=temp1->next;
        }

        while(temp2!=NULL){
            dummy->next=temp2;
            dummy=temp2;
            temp2=temp2->next;
        }

        return head->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;

        ListNode* mid=findmid(head);
        ListNode* right=mid->next;
        mid->next=NULL;
        
        ListNode* head1=sortList(head);
        ListNode* head2=sortList(right);

        return mergeit(head1,head2);
    }
};