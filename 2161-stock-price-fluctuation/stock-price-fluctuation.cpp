class StockPrice {
public:
    unordered_map<int ,int> timetoPrice;//unorderd map is implemented uding vector<list<pair<int,int>>> 
    // using hash function , and to reduce collison 
    map<int,int> PricetoFreq;// map is implemented using red black tree
    int latestTime;
    StockPrice() {
       int latestTime=0; 
    }
    
    void update(int timestamp, int price) {
        latestTime=max(latestTime,timestamp);
        // decrement PricetoFreq if same timeStamp comes
        
        if(timetoPrice.count(timestamp)){
            int oldPrice= timetoPrice[timestamp];
            timetoPrice[timestamp]=price;
            PricetoFreq[price]+=1;
            if(PricetoFreq[oldPrice]==1){
                PricetoFreq.erase(oldPrice);
            }
            else{
                PricetoFreq[oldPrice]-=1;
            }
        }
        else{
            timetoPrice[timestamp]=price;
            PricetoFreq[price]+=1;
        }
        
    }
    
    int current() {
        return timetoPrice[latestTime];
    }
    
    int maximum() {
        auto it=(--PricetoFreq.end());
        return it->first;
    }
    
    int minimum() {
       auto it =PricetoFreq.begin();
       return it->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */