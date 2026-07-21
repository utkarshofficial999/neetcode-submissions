#include <stack>

class MyQueue {
private:
    std::stack<int> s1; // Input stack
    std::stack<int> s2; // Output stack

public:
    MyQueue() {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int val = peek(); // Ensures s2 has elements
        s2.pop();
        return val;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};