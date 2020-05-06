
public class Solution {
    public int RectCover(int n) {
        if (n <= 2)
        return n;
    int pre2 = 1, pre1 = 2;
    int result = 0;
    for (int i = 3; i <= n; i++) {
        result = pre2 + pre1;
        pre2 = pre1;
        pre1 = result;
    }
    return result;
}
// 和青蛙跳台阶的思路一样，就是斐波那契数列