
import java.util.ArrayList;
public class Solution {
    public int minNumberInRotateArray(int [] nums) {
    if (nums.length==0)
        return 0;
    int l=0,h=nums.length-1;
    while(l<h){
        int m=l+(h-l)/2;
        if (nums[m]<=nums[h])
            h=m;
        else
            l=m+1;
    }
    return nums[l];
}
}

/* 注意到整个数组是由两个排序的数组组成的，所以就可以考虑采用二分法查找
首先找到中点，如果中点大于第一个元素 ，那么说明最小值一定在中点右边，如果
中点小于最后一个元素，则说明最小值一定在中点左边，注意由于原始数组是递增的
所以这两种情况是绝无可能共存的，这就很方便用if else。
 */