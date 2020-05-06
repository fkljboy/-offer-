
// 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
    int temp;
    int pop() {
        if (stack2.empty()){
            while(!stack1.empty()){
                temp=stack1.top();
                stack1.pop();
               stack2.push(temp);
                
            }
        }
       temp=stack2.top();
        stack2.pop();
        return temp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
/* 同样的cpp的解法中需要注意不能使栈中元素直接pop 而是要使用一个top方法获取栈顶的元素  
思路很明确一个栈负责入队 另一个栈负责将第一个栈的元素逆序弹出从而实现队列的“先进先出” */