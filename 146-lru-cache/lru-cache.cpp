class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node *next;
            Node *prev;
        Node(int _key,int _val){
            key=_key;
            val=_val;
        }


    };
    int cap;
    Node* Head=new Node(-1,-1);
    Node* Tail=new Node(-1,-1);
    unordered_map<int ,Node*> m;
    LRUCache(int _capacity) {
        cap=_capacity;
        Head->next=Tail;
        Tail->prev=Head;
    }
    void addNode(Node*newnode){
        Node *temp=Head->next;
        newnode->prev=Head;
        newnode->next=temp;
        Head->next=newnode;
        temp->prev=newnode;

    }
    void deleteNode(Node *delnode){
        Node *delnodeprev=delnode->prev;
        Node *delnodenext=delnode->next;
        delnodeprev->next=delnodenext;
        delnodenext->prev=delnodeprev;

    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node *resnode=m[key];
            int res=resnode->val;
            m.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            m[key]=Head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* res=m[key];
            deleteNode(res);
            m.erase(key);
            
        }
        if(m.size()==cap){
            m.erase(Tail->prev->key);
            deleteNode(Tail->prev);
        }
    
        addNode(new Node(key,value));
        m[key]=Head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */