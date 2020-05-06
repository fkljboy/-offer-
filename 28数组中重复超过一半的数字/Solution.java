public class Solution {
    public int MoreThanHalfNum_Solution(int [] nums) {
        int majority = nums[0];
    for (int i = 1, cnt = 1; i < nums.length; i++) {
        cnt = nums[i] == majority ? cnt + 1 : cnt - 1;
        if (cnt == 0) {
            majority = nums[i];
            cnt = 1;
        }
    }
    int cnt = 0;
    for (int val : nums)
        if (val == majority)
            cnt++;
    return cnt > nums.length / 2 ? majority : 0;
    }
}
/* java解法是分为了两部分，首先利用逻辑通过一个遍历找到了出现最多的数字
然后判断这个数字出现的次数是不是超过有一半 */