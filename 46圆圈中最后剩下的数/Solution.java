public class Solution {
    public int LastRemaining_Solution(int n, int m) {
         if(n < 1 || m < 1){
            return -1;
        }
        int last = 0;
        for(int i = 2; i <= n; i++){
            last = (last + m) % i;
        }
        return last;
    }
}
/* 数学归纳法，我们可以得到只有一个人玩游戏的时候结果是0
两个人的时候是一个人的结果加上m在对人数取余，后面届时如此
由此就可以递推出最后的结果 */