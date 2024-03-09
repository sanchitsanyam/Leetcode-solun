import java.util.*;
class Node{
    int data;
    Node next;
    public Node(int val){
        this.data=val;
        this.next=null;
    }
}
class MyLinkedList {
    Node  head;
    int length;   
    public MyLinkedList() {
        head=null;
        length=0;
    }
    
    public int get(int index) {
        if(index<0 || index>=this.length){
            return -1;
        }
          
        Node cur=this.head;
        for(int i=0;i<index;i++){
            cur=cur.next;
        }
        return cur.data;
    }
    
    public void addAtHead(int val) {
        Node newHead=new Node(val);
        newHead.next=this.head;
        this.head=newHead;
        this.length+=1;
    }
    
    public void addAtTail(int val) {
        if(this.length==0){
            addAtHead(val);
            return;
        }
        Node cur=this.head;
        while(cur.next !=null){
            cur=cur.next;
        }
        Node newtail=new Node(val);
        cur.next=newtail;
        this.length+=1;
        
    }
    
    public void addAtIndex(int index, int val) {
        if(index<0||index>this.length){
            return;
        }
        if(index==0){
            addAtHead(val);
            return;
        }
        Node cur=this.head;
        for(int i=0;i<index-1;i++){
            cur=cur.next;
        }
        Node newNode=new Node(val);
        newNode.next=cur.next;
        cur.next=newNode;
        this.length+=1;
        
    }
    
    public void deleteAtIndex(int index) {
        if(index<0|| index>=this.length){
            return;
        }
        if(index==0){
            Node secondNode=this.head.next;
            this.head= secondNode;
            this.length-=1;
            return ;
        }
        Node cur=this.head;
        for(int i=0;i<index-1;i++){
            cur=cur.next;
        }
        cur.next=cur.next.next;
        this.length-=1;
        
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */