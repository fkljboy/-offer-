class Solution {
private :
    stack<int> dataStack;
    stack<int> minStack;
public:
    void push(int value) {
        dataStack.push(value);
        if (minStack.empty()) minStack.push(value);
        if (minStack.top()>value) minStack.push(value);
    }
    void pop() {
        if (dataStack.top()==minStack.top()){
            minStack.pop();
        }
        dataStack.pop();
        
        
    }
    int top() {
        return dataStack.top();
    }
    int min() {
        return minStack.top();
    }
};
// 思路和java的一样 无非需要使用top方法 反而更方便