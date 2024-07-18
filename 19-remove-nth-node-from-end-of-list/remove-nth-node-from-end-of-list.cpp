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
        if(head==NULL || head->next==NULL)return NULL;
        int len=1;
        ListNode* curr=head;
        while(curr->next!=NULL){
            curr = curr->next;
            len++;
        }
        curr=head;
        for(int i=0;i<len-n-1;i++){
            curr = curr->next;
        }
        if(len==n){
            ListNode* temp=curr->next;
            curr->next=NULL;
            return temp;
        }    
        curr->next=(curr->next!=NULL)?curr->next->next: NULL;
        
        return head;  
  
    }
};