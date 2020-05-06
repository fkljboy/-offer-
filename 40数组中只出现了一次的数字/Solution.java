public class Solution {
    public void FindNumsAppearOnce(int [] array,int num1[] , int num2[]) {

        int length = array.length;
        if(length == 2){
            num1[0] = array[0];
            num2[0] = array[1];
            return;
        }
        int bitResult = 0;
        for(int i = 0; i < length; ++i){
            bitResult ^= array[i];
        }
        int index = findFirst1(bitResult);
        for(int i = 0; i < length; ++i){
            if(isBit1(array[i], index)){
                num1[0] ^= array[i];
            }else{
                num2[0] ^= array[i];
            }
        }
    }
     
    private int findFirst1(int bitResult){
        int index = 0;
        while(((bitResult & 1) == 0) && index < 32){
            bitResult >>= 1;
            index++;
        }
        return index;
    }
     
    private boolean isBit1(int target, int index){
        return ((target >> index) & 1) == 1;
    }

}
/* 我们从头到尾一次异或数组中的每一个数字，那么最终得到的结果就是
两个只出现一次的数组的异或结果。因为其他数字都出现了两次，在异或中
全部抵消了。由于两个数字肯定不一样，那么异或的结果肯定不为0，也就是
说这个结果数组的二进制表示至少有一个位为1。我们在结果数组中找到第一个
为1的位的位置，记为第n位。现在我们以第n位是不是1为标准把元数组中的
数字分成两个子数组，第一个子数组中每个数字的第n位都是1，而第二个子
数组中每个数字的第n位都是0。 */