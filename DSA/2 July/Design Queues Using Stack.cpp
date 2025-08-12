class MyQueue {
    stack<int> head, rear;

    void RearToHead(){
        while(!rear.empty()){
            head.push(rear.top());
            rear.pop();
        }
    }
public:
    MyQueue() {
        rear = stack<int>();
        head = stack<int>();
    }
    
    void push(int x) {
        rear.push(x);
    }
    
    int pop() {
        if(head.empty()) RearToHead();
        int temp = head.top();
        head.pop();
        return temp;
    }
    
    int peek() {
        if(head.empty()) RearToHead();
        return head.top();
    }
    
    bool empty() {
        return head.empty() && rear.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */