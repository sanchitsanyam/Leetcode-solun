class StockPrice {
public:
    unordered_map<int, int> TimeToPrice;
    map<int,int> PriceToFreq;
    int latestTime;
    StockPrice() {
       latestTime=0; 
    }
    
    void update(int timestamp, int price) {
        latestTime=max(latestTime,timestamp);
        if(TimeToPrice[timestamp]!=0){
            int oldPrice = TimeToPrice[timestamp];
            if(PriceToFreq[ oldPrice]==1){
                PriceToFreq.erase(oldPrice);
            }
            else{
                PriceToFreq[oldPrice]--;
            }

        }
        PriceToFreq[price]++;
        TimeToPrice[timestamp]= price;
    }
    
    int current() {
        return TimeToPrice[latestTime];
    }
    
    int maximum() {
        auto it= --PriceToFreq.end();
        return it->first;
    }
    
    int minimum() {
        auto it= PriceToFreq.begin();
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