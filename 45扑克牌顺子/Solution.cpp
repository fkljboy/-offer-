class Solution {
public:
    bool IsContinuous( vector<int> nums ) {
         if (nums.size()<5) return false;
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(auto num :nums ){
            if (num==0) cnt++;
        }
        for (int i=cnt;i<nums.size()-1;i++){
            if (nums[i+1]==nums[i]) return false;
            cnt-=nums[i+1]-nums[i]-1;
        }
        return cnt>=0;
    }
};
/* 首先我们对数组进行排序，排序之后0都在最前面，所以统计出
0的个数也就是癞子的个数，然后统计剩下的非零的数字之间的
差值，以得出需要癞子的个数，如果最后癞子刚好用完或者还有
多出的癞子这说明可以成顺子，否则就不行 */