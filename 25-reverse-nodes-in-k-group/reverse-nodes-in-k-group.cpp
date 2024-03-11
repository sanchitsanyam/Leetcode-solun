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
    void reverseList(ListNode* s,ListNode* e){
        ListNode *p=NULL,*c=s,*n=NULL;
        while(p!=e){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1||head==NULL||head->next==NULL)return head;
        ListNode* s=head;
        ListNode* e=head;
        int jumps=k-1;
        while(jumps--){
            e=e->next;
            if(e==NULL)return head;
        }
        ListNode* head_rem=reverseKGroup(e->next,  k);
        reverseList( s, e);
        s->next=head_rem;
        
        return e;
        
    }
};