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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
     if(head==NULL||head->next==NULL)return head;
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* temp=head;
        ListNode* temp1=head;

        while(temp->next!=NULL){
            ListNode*temp2= new ListNode(__gcd(temp->val,temp->next->val));
            ListNode* temp3=temp->next;
            temp->next=temp2;
            temp2->next=temp3;
            temp2=temp2->next;
            temp=temp2;
        
        }
        return dummy->next;
    }
};