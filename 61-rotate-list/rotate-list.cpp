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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        if(k==0)return head;
        int len=1;
        ListNode* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
            len++;
        }
        k = k % len;
        ListNode*curr1=head;
        curr->next=head;
        curr->next=head;
        int n=len-k-1;
        for(int i=0; i<n ; i++){
            curr1=curr1->next;
        }
        ListNode* curr2=curr1->next;
        curr1->next=NULL;
        return curr2;
    }
};