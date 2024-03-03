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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode* temp=head;
        while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        int k=l-n;
        temp=head;
        ListNode* prev=NULL;
        if(k==0)return head->next;
        while(k--){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        return head;
    }
};