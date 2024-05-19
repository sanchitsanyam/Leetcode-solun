
struct Node {
    int key,val,cnt;
    Node* prev;
    Node* next;
    Node(int k,int v){
        key=k;
        val=v;
        cnt=1;
    }
};
struct List{
    int size;
    Node* Head;
    Node* Tail;
    List(){
        Head=new Node(0,0);
        Tail=new Node(0,0);
        Head->next=Tail;
        Tail->prev=Head;
        size=0;
    }
    void addfront(Node *node){
        Node* temp=Head->next;
        node->next=temp;
        node->prev=Head;
        temp->prev=node;
        Head->next=node;
        size++;
    }
    void delnode(Node* del){
        Node* delprev=del->prev;
        Node* delnext=del->next;
        delnext->prev=delprev;
        delprev->next=delnext;
        size--;
    }
}; 
class LFUCache {
    map<int,Node*> keyNode;
    map<int ,List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int CurrSize;
public:
    LFUCache(int capacity) {
        maxSizeCache=capacity;
        minFreq=0;
        CurrSize=0;
    }
    void updatefreqListMap(Node * node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->delnode(node);
        if(node->cnt==minFreq &&freqListMap[node->cnt]->size==0){
            minFreq++;
        }
        List*nextHigherFreqList=new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
            nextHigherFreqList=freqListMap[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherFreqList->addfront(node);
        freqListMap[node->cnt]=nextHigherFreqList;
        keyNode[node->key]=node;
    }
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node *node=keyNode[key];
            int value=node->val;
            updatefreqListMap(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if( maxSizeCache==0){
            return;
        }
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->val=value;
            updatefreqListMap(node);
        }
        else{
            if(maxSizeCache==CurrSize){
                List* list = freqListMap[minFreq];
                keyNode.erase(list->Tail->prev->key);
                freqListMap[minFreq]->delnode(list->Tail->prev);
                CurrSize--;
            }
            CurrSize++;
            // new value has to be added who is not there previously
            minFreq=1;
            List* listFreq=new List();
            if(freqListMap.find(minFreq) !=freqListMap.end()){
                listFreq=freqListMap[minFreq];
            }
            Node* node =new Node(key,value);
            listFreq->addfront(node);
            keyNode[key]=node;
            freqListMap[minFreq]=listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */