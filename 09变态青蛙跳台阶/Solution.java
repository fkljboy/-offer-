import java.util.Arrays;

public class Solution {
    public static void main(String[] args) {
        int a=JumpFloorII(3);
            System.out.println(a);
    }
    public static int JumpFloorII(int target) {
          int[] dp = new int[target];
        Arrays.fill(dp, 1);
    for (int i = 1; i < target; i++)
        for (int j = 0; j < i; j++)
            dp[i] += dp[j];
    return dp[target - 1];
    }
}
/* 原理类似于cpp解法 但是java可以方便的使用Array的fill方法，迅速将数组元素置1 */