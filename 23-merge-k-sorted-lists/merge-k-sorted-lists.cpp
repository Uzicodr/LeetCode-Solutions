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
    ListNode* mergetwo(ListNode* head1,ListNode* head2){
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }

        ListNode* dummy=new ListNode(-1);
        ListNode* newhead=dummy;

        ListNode* temp1=head1;
        ListNode* temp2=head2;

        while(temp1 && temp2){
            if(temp1->val<=temp2->val){
                newhead->next=temp1;
                newhead=newhead->next;
                temp1=temp1->next;
            }
            else if(temp2->val<temp1->val){
                newhead->next=temp2;
                newhead=newhead->next;
                temp2=temp2->next;
            }
        }

        while (temp1){
            newhead->next=temp1;
            newhead=newhead->next;
            temp1=temp1->next;
        }
        while (temp2){
            newhead->next=temp2;
            newhead=newhead->next;
            temp2=temp2->next;
        }

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
        return nullptr;

        ListNode* realhead=lists[0];

        for(int i=1;i<lists.size();i++){
            realhead=mergetwo(lists[i],realhead);
        }
        return realhead;
    }
};