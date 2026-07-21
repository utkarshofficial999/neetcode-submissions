#include <stack>
#include <algorithm>

class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> minStack;

public:
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        
        // Use std::min instead of std::main
        if (!minStack.empty()) {
            val = std::min(val, minStack.top());
        }
        
        minStack.push(val);
    }
    
    void pop() {
        stack.pop();      // Fixed typo: satck -> stack
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top(); // Capitalization matches declaration
    }
};