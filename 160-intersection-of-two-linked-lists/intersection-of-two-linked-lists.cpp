/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        ListNode* curA=headA;
        ListNode* curB=headB;
        bool flag=false;
        while(curA !=curB){
            curA=curA->next;
            if(curA==NULL){
               curA=headB; 
               if(flag)return NULL;
               flag=true;
            }
            curB=curB->next;
            if(curB==NULL)curB=headA;
        }
        return curA;
    }
};