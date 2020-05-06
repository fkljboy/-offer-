/* 大家都知道斐波那契数列，现在要求输入一个整数n，
请你输出斐波那契数列的第n项（从0开始，第0项为0）。n<=39 */
class Solution {
public:
    
    int Fibonacci(int n) {
          int f[n];
        f[0]=0;
        f[1]=1;
        for(int i=2;i<=n;i++){
            f[i]=f[i-1]+f[i-2];
        }
        return f[n];
    }
};

//最简单的动态规划