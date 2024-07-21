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
    ListNode* reverse(ListNode* s ,ListNode* e ,ListNode*spre ,ListNode*enxt ,ListNode* head,int left){
        
        ListNode* p=NULL;
        ListNode* c=s;
        ListNode* n=NULL;
        while(p!=e){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        if(s!=NULL)s->next=enxt;
        if(left!=0)spre->next=e;
        ListNode* ans= head;
        if(left==0){
            return p;
        }
        return ans;
        

    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL || head->next==NULL || left==right)return head;
        left--;
        right--;
        ListNode* curr1=head;
        ListNode* curr2=head;
        for(int i=0;i<left-1;i++){
            curr1=curr1->next;
        }
        for(int i=0;i<right;i++){
            curr2=curr2->next;
        }
        ListNode* s=curr1->next;
        ListNode*  spre=curr1;
        if(left==0){
            s=head;
        }
        return reverse(s,curr2,spre,curr2->next, head,left);
      
    }
};