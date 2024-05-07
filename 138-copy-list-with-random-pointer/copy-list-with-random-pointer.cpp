/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node *cur=head;
        //cloned node adding
        while(cur !=NULL){
            Node* newNode =new Node(cur->val);
            newNode->next=cur->next;
            cur->next=newNode;
            cur=newNode->next;
        }
        // attaching random as in original list
        Node* ptr=head;
        while(ptr!=NULL){
            ptr->next->random=(ptr->random!=NULL)?ptr->random->next:NULL;
            ptr=ptr->next->next;
        }
        // weaving out(seperately original one and Clone One)
        Node *ptr_oldL=head;
        Node *ptr_newL=head->next;
        Node *copiedHead=head->next;
        while(ptr_oldL!=NULL){
            ptr_oldL->next=ptr_oldL->next->next;
            ptr_newL->next=(ptr_newL->next!=NULL)?ptr_newL->next->next:NULL;
            ptr_oldL=ptr_oldL->next;
            ptr_newL=ptr_newL->next;

        }
        return copiedHead;
    }
};