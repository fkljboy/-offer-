class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
         if (array.size()==0){
            return 0;
        }
        int max=array[0];
        int cur=array[0];
        for (int i=1;i<array.size();i++){
            if (cur<0)
                cur=array[i];
            else cur+=array[i];
            if(cur>max){
                max=cur;
            }
        }
        return max;
    }
};
/* 把整个数组往前滚就完事了，如果累加上最新值的和小于0，则前面的一律
作废，从最新值开始重新进行累加，记住要将最小值进行保存 */