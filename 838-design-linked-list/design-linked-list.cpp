class Node{
    public:    
        int data;
        Node* next;
        
        Node(int value){
            data=value;
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
        if(index < 0 || index >= this->length){
            return -1;
        }
        Node *cur=this->head;
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        return cur->data;
    }
    
    void addAtHead(int val) {
        Node *newHead = new Node(val);
        newHead->next=this->head;
        this->head=newHead;
        this->length +=1;

        
    }
    
    void addAtTail(int val) {
        if(this->length==0){
            addAtHead(val);
            return;
        }
        Node  *curr=this->head;
        while(curr->next!=NULL){
              curr=curr->next;
        }
        Node* newTail=new Node(val);
        curr->next = newTail;
        this->length += 1;

        
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index > this->length ){
            return ;
        }
        if(index==0){
           addAtHead(val);
           return; 
        }
        if(index==this->length){
           addAtTail(val); 
           return;
        }
        Node* cur =this->head;
        for(int i=0;i<index-1;i++){
            cur=cur->next;
        }
        Node* atIndex=new Node(val);
        atIndex->next=cur->next;
        cur->next=atIndex;
        this->length +=1;

    }
    void deleteAtHead(){
        if(this->length <=0){
            return;
        }
        Node* oldHead=this->head;
        this->head=head->next;
        this->length-=1;
        delete oldHead;

    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=this->length){
            return ;
        }
        if(index==0){
            deleteAtHead();
            return;
        }
        Node* curr =this->head;
        for(int i=0;i<index-1;i++){
            curr=curr->next;
        } 
        Node* oldNode=curr->next;
        curr->next=curr->next->next;
        this->length-=1;
        delete oldNode;

        
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