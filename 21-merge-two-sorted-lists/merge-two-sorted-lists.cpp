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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        return list2;

        if(list2==NULL)
        return list1;

        ListNode* temp1=list1;
        ListNode* temp2=list2;

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

        while(temp1){
            dummy->next=temp1;
            dummy=temp1;
            temp1=temp1->next;
        }

        while(temp2){
            dummy->next=temp2;
            dummy=temp2;
            temp2=temp2->next;
        }

        return head->next;
    }
};