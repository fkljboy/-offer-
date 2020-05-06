
public class Solution {
    public void reOrderArray(int [] array) {
        int len=array.length-1;
        for (int i=len;i>0;i--){
            for(int j=0;j<i;j++){
                if(isEven(array[j])&&!isEven(array[j+1]))
                    swap(array,j,j+1);
            }
        }
    }
    private boolean isEven(int a){
        return a%2==0;
    }
    private void swap(int[] array,int a,int b){
        int t=array[a];
        array[a]=array[b];
        array[b]=t;
    }
}
/* 该解法运用的是冒泡的思维，使每一个偶数都和它的下一个数做比较，如果是奇数则
交换，这样就可以将所有的偶数都顺序冒泡到数组的后端，空间复杂度小而时间复杂度大 */