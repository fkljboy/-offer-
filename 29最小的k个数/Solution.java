import java.util.Collections;
import java.util.ArrayList;
import java.util.Set;
import java.util.TreeSet;
public class Solution {
    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        Set<Integer> a = new TreeSet<Integer>();
        int num=0;
        ArrayList<Integer> res=new ArrayList<> ();
        if (input.length<k||k==0) return res;
        for(int i=0;i<input.length;i++){
            a.add(input[i]);
        }
        for (int i: a){
            res.add(i);
            num++;
            if(num>=k) break;
        }
        return res;
    }
}
/* 这实际上是一种偷懒的算法，就是利用set的排序能力去解决，但是其实有时间复杂
度更优的快排方法 */