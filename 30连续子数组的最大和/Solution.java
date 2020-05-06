public class Solution {
    public int FindGreatestSumOfSubArray(int[] array) {
        if (array.length==0){
            return 0;
        }
        int max=array[0];
        int cur=array[0];
        for (int i=1;i<array.length;i++){
            if (cur<0)
                cur=array[i];
            else cur+=array[i];
            if(cur>max){
                max=cur;
            }
        }
        return max;
    }
}
// 思路同cpp解法