public class Solution {
    public String LeftRotateString(String str,int n) {
       if(n>=str.length())
           return str;
        char[] c=str.toCharArray();
        reverse(c,0,n-1);
        reverse(c,n,str.length()-1);
        reverse(c,0,str.length()-1);
        return new String(c);
    }
    private void reverse(char[] c,int i,int j){
        while (i<j)
            swap (c,i++,j--);
    }
    private void swap(char[] c,int i,int j){
        char t=c[i];
        c[i]=c[j];
        c[j]=t;
    }
}
// 方法与cpp方法相同