public class Solution {
    public int NumberOf1(int n) {
         int sum=0;
        while(n!=0){
            n &=(n-1);
            sum++;
        }
        return sum;
    }
}
// 思路同cpp解法