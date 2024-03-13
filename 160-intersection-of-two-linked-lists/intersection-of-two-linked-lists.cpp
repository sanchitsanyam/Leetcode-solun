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
    int getLength(ListNode* node){
        int len=0;
        ListNode* cur=node;
        while(cur!=NULL){
            cur=cur->next;
            len++;
        }
        return len;
    }
    ListNode* giveTheEdge(ListNode* head,int extra){
        ListNode* cur=head;
        for(int i=0;i<extra;i++){
            cur=cur->next;
        }
        return cur;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=getLength(headA);
        int len2=getLength(headB);
        ListNode* curA=headA;
        ListNode* curB=headB;
        if(len1 >len2){
            curA=giveTheEdge( headA,len1-len2);
        }
        else{
            curB=giveTheEdge( headB,len2-len1);
        }
        while(curA !=curB){
            curA=curA->next;
            curB=curB->next;
        }
        return curA;
    }
};