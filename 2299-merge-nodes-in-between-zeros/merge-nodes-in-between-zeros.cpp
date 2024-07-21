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
    ListNode* mergeNodes(ListNode* head) {
        int cnt=0;
        int sum=0;
        ListNode* curr=head;
        while(curr!=NULL){
            if(curr->val==0){
                cnt++;
            }
            sum+=curr->val;
            curr=curr->next;
            if(cnt==2){
                break;
            }
           
        }
        ListNode* head1=new ListNode(sum);
        sum=0;
        ListNode* curr1=head1;
        while(curr!=NULL){
            sum +=curr->val;
            if(curr->val==0 ){
               
                ListNode* node=new ListNode(sum); \
               curr1->next=node;
               sum=0;
               curr1=curr1->next;
            }
            
            curr=curr->next;
        }
        return head1;
    }
};