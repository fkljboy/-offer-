import java.util.ArrayList;
public class Solution {
    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
       ArrayList<ArrayList<Integer> > result=new ArrayList<> ();
       if (sum<=2) return result;
       int low=1,high=2;
       while (high>low){
           int num=(high+low)*(high-low+1)>>1;
           if (sum>num){
               high++;
           }
           else if(sum<num){
               low++;
           }
           else if (sum==num){
               ArrayList<Integer> temp =new ArrayList<Integer> ();
               for (int i=low;i<=high;i++) temp.add(i);
               result.add(temp);
               low++;
           }
           
       }
        return result;
    }
}
