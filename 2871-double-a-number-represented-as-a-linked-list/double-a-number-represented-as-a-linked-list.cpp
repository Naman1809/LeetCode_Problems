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
    ListNode* reverse(ListNode* head){
    if(head==NULL||head->next==NULL)return head;
    ListNode *curr=head, *prev=NULL,* next=NULL;
    while(curr!=NULL){
        next= curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;}
    ListNode* doubleIt(ListNode* head) {
        ListNode *temp=head;
        ListNode *temp1= reverse(temp);
        int car=0;
        ListNode* temp2=temp1;
        while(temp1!=NULL){
            int c=temp1->val*2+car;
            temp1->val=c%10;
            car=c/10;
            temp1=temp1->next;
        }
        if(car){
            ListNode *ans=new ListNode(1);
            ans->next=reverse(temp2);
            return ans;
        }
        return reverse(temp2);
    }
};