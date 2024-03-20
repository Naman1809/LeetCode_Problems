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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode *temp=list1;
        ListNode *prev1,*prev2;
        int c=0;
        while(temp!=NULL){
            if(c==a-1){
                prev1=temp;
            }
            if(c==b){
                prev2=temp->next;
            }
            c++;
             temp=temp->next;
          /*  if(temp->next->val==a){
                prev1=temp;
            }
            if(temp->val==b){
                        prev2=temp->next;      
                              }
           */
        }
        
        ListNode * temp1=list2;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
     
        if(a==0){
            if(prev2==NULL){
                return list2;
            }
            else{
                list1->next=list2;
                temp1->next=prev2;
                return list1->next;
            }
        }
        else{
            if(prev2==NULL){
                prev1->next=list2;
                return list1;
            }
            else{
                prev1->next=list2;
                temp1->next=prev2;
                return list1;
                
            }
        }
        
    }
};