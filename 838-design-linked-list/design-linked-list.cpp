
class Node{
public:    
    Node * next;
    int data;
    Node(int val){
        data=val;
        next=NULL;
    }

};
class MyLinkedList {
    Node* head;
    int length;
public:
    MyLinkedList() {
       head=NULL;
       length=0;
    }
    
    int get(int index) {
        
        Node *curr=head;
        for(int i=0;i<index && curr!=NULL;i++){
            curr=curr->next;
        }
        return(curr==NULL)?-1 : curr->data;
    }
    
    void addAtHead(int val) {
        Node* newNode= new Node(val);
        newNode->next=head;
        head=newNode;
        length++;
    }
    
    void addAtTail(int val) {
        if(head==NULL){
            addAtHead(val);
            return;
        }
        Node * curr=head;
        for(int i=0;i<length-1;i++){
            curr=curr->next;
        }
        Node* newNode= new Node(val);
        curr->next=newNode;
        length++;

        
    }
    
    void addAtIndex(int index, int val) {
        if(index > length || index<0){
           return;
        }
        if(index==0){
           addAtHead(val);
           return ; 
        }
        if(index==length){
            addAtTail(val);
            return;
        }
        Node* curr=head;
        for(int i = 0; i < index-1; i++){
            curr=curr->next;
        }
        Node* newNode= new Node(val);
        newNode->next=curr->next;
        curr->next=newNode;
        length++;
    }
    void deleteAtHead(){
        if(length==0)return;
        Node * temp=head;
        head=head->next;
        delete temp;
        length--;
    }
    void deleteAtTail(){
        Node * curr=head;
        for(int i=0;i<length-2;i++){
            curr=curr->next;
        }
        Node * temp=curr->next;
        curr->next=NULL;
        delete temp;
        length--;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=length)return;
        if(index==0){
           deleteAtHead();
           return;
        }
        if(index==length-1){
           deleteAtTail();
           return;
        }
        Node * curr=head;
        for(int i=0;i<index-1;i++){
            curr=curr->next;
        }
        Node * temp=curr->next;
        curr->next=curr->next->next;
        delete temp;
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */