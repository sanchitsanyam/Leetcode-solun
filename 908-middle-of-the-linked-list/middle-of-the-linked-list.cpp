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
    ListNode* middleNode(ListNode* head) {
        // int len=0;
        // ListNode* cur=head;
        // while(cur!=NULL){
        //     cur=cur->next;
        //     len++;
        // }
        // ListNode* cur1=head;
        // int half_len=len/2;
        // while(half_len--){
        //     cur1=cur1->next;
        // }
        // return cur1;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast !=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};