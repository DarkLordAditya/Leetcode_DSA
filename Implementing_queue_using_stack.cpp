
#include <iostream>
#include <deque>
using namespace std;

class MyQueue {
public:
    deque<int> stack; 

    MyQueue() {
    }
    
    void push(int x) {
        stack.push_back(x);
    }
    
    int pop() {
        int val = stack.front(); 
        stack.pop_front();
        return val;
    }   
    int peek() {
        return stack.front();    
    }   
    bool empty() {
        return stack.empty();
    }
};


int main() {
    MyQueue st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Front element: " << st.peek() << endl;

    while (!st.empty()) {
        cout << "Popped: " << st.pop() << endl;
    }

    return 0;
}