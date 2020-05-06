public class Solution {
    public int GetNumberOfK(int [] nums , int K) {
       int first = binarySearch(nums, K);
    int last = binarySearch(nums, K + 1);
    return (first == nums.length || nums[first] != K) ? 0 : last - first;
}

private int binarySearch(int[] nums, int K) {
    int l = 0, h = nums.length;
    while (l < h) {
        int m = l + (h - l) / 2;
        if (nums[m] >= K)
            h = m;
        else
            l = m + 1;
    }
    return l;
    }
}
/* 这个解法更妙，只用找first，然后直接找k+1的位置即可
哪怕k+1不存在，也可以返回重复目标数后面的第一个数
二分法牛逼！ */