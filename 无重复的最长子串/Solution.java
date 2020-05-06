import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int longestString(String s){
        int len=s.length();
        int res=0;
        int end=0,start=0;
        Set<Character> set=new HashSet<>();
        while (start<len&&end<n){
            if (set.contains(s.charAt(end))){
                set.remove(s.charAt(start++))
            }
            else{
                set.add(s.charAt(end++));
                res=Math.max(res,end-start);
            }
        }
        retunr res;
}
}