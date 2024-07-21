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
    ListNode* reverse(ListNode* s){
        ListNode* p=NULL;
        ListNode* c=s;
        ListNode* n=NULL;
        while(c!=NULL){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;

    }
    int pairSum(ListNode* head) {
        ListNode* head1=new ListNode(head->val);
        ListNode* curr1=head1;
        ListNode* curr=head;
        curr=curr->next;
        while(curr!=NULL){
            ListNode* node=new ListNode(curr->val);
            curr1->next=node;
            curr=curr->next;
            curr1=curr1->next;
        } 
        ListNode* head3=reverse(head1); 
        ListNode* curr2=head;
        ListNode* curr3=head3;
        int maxTwin=INT_MIN;
        while(curr2!=NULL ){
            maxTwin=max(maxTwin,curr2->val + curr3->val); 
            curr2=curr2->next;
            curr3=curr3->next;
        }
        return maxTwin;
    }
};