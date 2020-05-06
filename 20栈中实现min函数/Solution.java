import java.util.Stack;
 
public class Solution {
   

Stack<Integer> data = new Stack<Integer>();
    Stack<Integer> min = new Stack<Integer>();
    Integer temp = null;
    public void push(int node) {
        if(temp != null){
            if(node <= temp ){
                temp = node;
                min.push(node);
            }
            data.push(node);
        }else{
            temp = node;
            data.push(node);
            min.push(node);
        }
    }
     
    public void pop() {
        int num = data.pop();
        int num2 = min.pop();
        if(num != num2){
           min.push(num2);
        }
    }
     
    public int top() {
        int num = data.pop();
        data.push(num);
        return num;
    }
     
    public int min() {
        int num = min.pop();
        min.push(num);
        return num;
    }
}
设置一个辅助栈来存在数据栈中所有的局部最小值，并将最小值里面的最小值
存入中间变量temp中
由于java的pop是弹出加返回，所以如果min栈和data栈返回的数字不一致
则说明弹出的数并不是最小数，则将该数再弹回去