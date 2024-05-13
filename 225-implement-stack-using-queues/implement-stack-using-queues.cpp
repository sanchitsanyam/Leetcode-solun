class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()!=1){
            int t=q1.front();
            q2.push(t);
            q1.pop();
        }
        int x=q1.front();
        q1.pop();
        while(q2.size()){
            int t=q2.front();
            q1.push(t);
            q2.pop();
        }
        return x;
    }
    
    int top() {
       return q1.back(); 
    }
    
    bool empty() {
        return (q1.size()==0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */