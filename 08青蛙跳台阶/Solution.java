
public class Solution {
    public int JumpFloor(int n) {
        if(n <= 1)
    return n;
    // 先创建一个数组来保存历史数据
    int[] dp = new int[n+1];
    // 给出初始值
    dp[0] = 0;
    dp[1] = 1;
    dp[2]=2;
    // 通过关系式来计算出 dp[n]
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    // 把最终结果返回
    return dp[n];
    }
}
// 注意初始值和斐波那契数列的不同