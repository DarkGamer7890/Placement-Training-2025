#include<bits/stdc++.h>
using namespace std;

class Stack{
    int* arr;
    int size;
    int index;

public:
    Stack() {                  // default constructor with size 10
        size = 10;
        arr = new int[size];
        index = 0;
    }

    Stack(int n){
        size = n;
        arr = new int[size];
        index = 0;
    }

    void push(int x){
        if(index >= size){
            cout << "Stack Overflow\n";
            return;
        }

        arr[index++] = x;
    }

    int pop(){
        if(index <= 0){
            cout << "Stack Underflow\n";
            return INT_MIN;
        }

        return arr[--index];
    }

    int top(){
        return arr[index - 1];
    }

    int peep(int i){
        return arr[i];
    }

    void print(){
        for(int i = 0; i < index; ++i) cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();

    s.push(6);
    s.print();

    cout << s.top() << endl;
    cout << s.peep(0) << endl;

    cout << s.pop() << endl;
    s.print();

    cout << s.pop() << endl;
    s.print();

    cout << s.pop() << endl;
    s.print();

    cout << s.pop() << endl;
    s.print();

    cout << s.pop() << endl;
    s.print();

    cout << s.pop() << endl;
    s.print();

    return 0;
}