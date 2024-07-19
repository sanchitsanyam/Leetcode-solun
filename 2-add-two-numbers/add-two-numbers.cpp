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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long s=0;
        long long rem=0;
        long long t=((l1!=NULL)?l1->val:0)+((l2!=NULL)? l2->val:0);
        s=((t+rem)%10); 
        ListNode* head= new ListNode(s);
        ListNode* curr=head;
        rem=(t+rem)/10;
        (l1!=NULL)?l1=l1->next:l1=NULL;
        (l2!=NULL)?l2=l2->next:l2=NULL;
        while(l1!=NULL || l2!=NULL){
              t=((l1!=NULL)?l1->val:0)+((l2!=NULL)? l2->val:0);
              s=((t+rem)%10);
              ListNode* node= new ListNode(s);
              curr->next=node;
              curr=curr->next;
              rem=(t+rem)/10;
              (l1!=NULL)?l1=l1->next:l1=NULL;
              (l2!=NULL)?l2=l2->next:l2=NULL;
        }
        s=rem;
       
        while(s!=0){
            long long x=s%10;
            ListNode * node=new ListNode(x);
            curr->next=node;
            curr=curr->next;
            s=s/10;
        }
        return head;
    }
};