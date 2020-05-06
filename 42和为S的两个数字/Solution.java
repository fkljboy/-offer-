import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> FindNumbersWithSum(int [] array,int sum) {
         ArrayList<Integer> result=new ArrayList<> ();
        int len =array.length;
        int l=0,h=len-1;
        while (l<h){
            if (sum==array[l]+array[h]){
                result.add(array[l]);
                result.add(array[h]);
                break;
            }
            else if (sum>array[l]+array[h]) l++;
            else h--;
        }
        return result;
        
    }
}
//解法和cpp版本一致