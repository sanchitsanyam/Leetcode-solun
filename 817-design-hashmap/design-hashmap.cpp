class MyHashMap {
public:
    vector<list<pair<int,int>>> m;
    int siz ;
    MyHashMap() {
        siz=100;
        m.resize(siz);
    }
    int Hash(int key){
        return key%siz;
    }
    list<pair<int,int>>:: iterator Search(int key){
        int i= Hash(key);
        list<pair<int,int>>:: iterator it= m[i].begin();
        while(it != m[i].end()){
            if(it->first==key)return it;
            it++;
        }
        return m[i].end();
    }
    void put(int key, int value) {
        int i =Hash(key);
        if(contains(key)){
            list<pair<int,int>>:: iterator it=Search(key);
            it->second=value;
        }
        else{
            m[i].push_back({key,value});
        }
    }
    
    int get(int key) {
        if(!contains(key))return-1;
        else{
            list<pair<int,int>>:: iterator it=Search(key);
            return it->second;
        }
        
    }
    
    void remove(int key) {
        if(!contains(key))return;
        else{
            int i = Hash(key);
            list<pair<int,int>>:: iterator it=Search(key);
            m[i].erase(it);
            
        }
    }
    bool contains(int key){
        int i=Hash(key);
        if(Search(key)!=m[i].end())return true;
        else return false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */