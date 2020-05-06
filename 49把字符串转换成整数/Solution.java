public class Solution {
    public int StrToInt(String str) {
          if(str == null || str.length() == 0)return 0;
       int start;
       int tag ;
       if(str.charAt(0)=='+'){
           tag = 1;
           start = 1;
       }
       else if (str.charAt(0)=='-') {
        tag = 0;
        start =1;
    }else {
        tag = 1;
        start = 0;
    }
       long result = 0;
       for(int i=start;i<str.length();i++){
           char tmp = str.charAt(i);
           if(tmp >= '0'&& tmp<='9'){
               result = result*10 +(tmp-'0');
               if(tag == 1 && result>Integer.MAX_VALUE)
                   throw new RuntimeException("上溢出");
               if(tag == 0 && result<Integer.MIN_VALUE)
                   throw new RuntimeException("下溢出");
           }
           else {
            return 0;
        }
       }
        
        if(tag == 0)
            return (int) (-1*result);
        else {
            return (int) result;
        }
    }
}
