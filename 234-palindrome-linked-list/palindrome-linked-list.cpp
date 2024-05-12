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
    ListNode* reverseList(ListNode* head) {
       // https://www.geeksforgeeks.org/reverse-a-linked-list/
        if(head==NULL || head->next==NULL)return head;
        ListNode *p=NULL,*c=head,*n=NULL;
        while(c!=NULL){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL ||head->next==NULL)return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;

        }
        ListNode* newHead=reverseList(slow->next);   
        ListNode* fhalf=head;//first->half
        ListNode* shalf=newHead;//second->half
        while(shalf !=nullptr ){
            if(fhalf->val!=shalf->val){
                return false;
            }
            fhalf=fhalf->next;
            shalf=shalf->next;
        }
        return true;
    }
};