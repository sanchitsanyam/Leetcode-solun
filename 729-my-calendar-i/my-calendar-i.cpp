class MyCalendar {
public:
    
   
    vector<vector<int>> ans;
    MyCalendar() {
       
    }
    
    bool book(int start, int end) {
        
        
        int n=ans.size();
        for(int i=0;i<n;i++){
            if(ans[i][1]>start && ans[i][0]<end){
                return false;
            }
        }
        vector<int> a(2);
        a[0]=start;
        a[1]=end;
        ans.push_back(a);
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */