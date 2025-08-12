#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
    stack<int> head, rear;

    void RearToHead(){
        while(!rear.empty()){
            head.push(rear.top());
            rear.pop();
        }
    }

    public:
    int front(){
        if(isEmpty()) throw runtime_error("Queue is Empty");
        if(head.empty() && !rear.empty()) RearToHead();
        return head.top();
    }

    void enqueue(int n){
        rear.push(n);
    }

    int dequeue(){
        if(isEmpty()) throw runtime_error("Queue Underflow\n");
        else if(head.empty() && !rear.empty()) RearToHead();

        int temp = head.top();
        head.pop();
        return temp;
    }

    bool isEmpty(){
        return rear.empty() && head.empty();
    }

    int size(){
        return rear.size() + head.size();
    }

    void display(){                   // Question was to design queue using stack display function is for my convenience but queue is implemented using stack only
        vector<int> temp;

        while(!head.empty()){
            temp.push_back(head.top());
            head.pop();
        }

        RearToHead();

        while(!head.empty()){
            temp.push_back(head.top());
            head.pop();
        }

        for(int i = 0; i < temp.size(); ++i) cout << temp[i] << " ";
        cout << endl;

        for(int i = temp.size() - 1; i >= 0; --i) head.push(temp[i]);
    }
};

int main(){
    Queue q1;

    q1.enqueue(1);
    cout << "front : " << q1.front() << endl;

    q1.enqueue(2);
    cout << "front : " << q1.front() << endl;

    q1.enqueue(3);
    cout << "front : " << q1.front() << endl;

    q1.enqueue(4);
    cout << "front : " << q1.front() << endl;

    q1.display();
    cout << "size : " << q1.size() << endl;

    cout << q1.dequeue() << endl;
    cout << "front : " << q1.front() << endl;
    cout << "size : " << q1.size() << endl;

    cout << q1.dequeue() << endl;
    cout << "front : " << q1.front() << endl;
    cout << "size : " << q1.size() << endl;

    cout << q1.dequeue() << endl;
    cout << "front : " << q1.front() << endl;
    cout << "size : " << q1.size() << endl;

    cout << "Empty : " << q1.isEmpty() << endl;

    cout << q1.dequeue() << endl;
    cout << "front : " << q1.front() << endl;
    cout << "Empty : " << q1.isEmpty() << endl;

    cout << q1.dequeue() << endl;
}
