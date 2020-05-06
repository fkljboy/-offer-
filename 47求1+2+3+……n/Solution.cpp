/* 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、
case等关键字及条件判断语句（A?B:C）。 */
class Solution {
public:
    int Sum_Solution(int n) {
        int ans=n;
        ans&&(ans+=Sum_Solution(n-1));
        return ans;
    }
};
/* 这里利用的是&&的短路性质，当递归达到n<=0的时候，&&直接短路，返回上一层
并对结果实现累加 */