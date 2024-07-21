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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL ||head->next==NULL)return head;
        ListNode* odd_head=head;
        ListNode* head2=head->next;
        ListNode* even_head=head->next;
        while(even_head!=NULL ){
            if(odd_head!=NULL && even_head!=NULL)odd_head->next=even_head->next;
            if(odd_head!=NULL)odd_head=odd_head->next;
            if(odd_head!=NULL && even_head!=NULL)even_head->next=odd_head->next;
            if(even_head!=NULL)even_head=even_head->next;
        }
        ListNode* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=head2;
        return head;
    }
};