/* 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法
（先后次序不同算不同的结果）。 */
class Solution {
public:
    int jumpFloor(int n) {
        if(n <= 2)
    return n;
    
   int  p1=1;
   int p2=2;
   int p;

    for(int i = 3; i <= n; i++){
       p=p1+p2;
       p1=p2;
       p2=p;
    }
    return p;
    }
};
// 可以用动态规划解决 