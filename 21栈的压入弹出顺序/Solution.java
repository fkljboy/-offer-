import java.util.ArrayList;
import java.util.Stack;
public class Solution {
    private Stack<Integer> stackData = new Stack<> ();
    public boolean IsPopOrder(int [] pushA,int [] popA) {
       if(pushA.length == 0){
            return false;
        }
        for(int i = 0, j = 0; i < pushA.length;i++){
            stackData.push(pushA[i]);
            while(j < popA.length && stackData.peek() == popA[j]){
                stackData.pop();
                j++;
            }
        }
        return stackData.isEmpty();
       
    }
}
// 解法与c++相同