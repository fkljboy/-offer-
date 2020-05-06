class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n==0)
            return -1;
        if (n==1)
            return 0;
        return (LastRemaining_Solution(n-1,m)+m)%n;
    }
};
/* 约瑟夫环的递归解法，每一轮的胜者都是初始位置加指定数m再除以n的余数
然后这个胜者的位置又变成了下一次报数的初始位置 */