class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {
        q1 = queue<int>();
        q2 = queue<int>();
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q2.empty()){
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
        }

        int temp = q1.front();
        q1.pop();

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

        return temp;
    }
    
    int top() {
        if(q1.size()) return q1.back();
        return q2.front();
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->front();
 * bool param_4 = obj->empty();
 */