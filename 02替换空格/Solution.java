import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        StringBuffer str2=new StringBuffer();
        str2.append(sc.nextLine());
        String str1=replaceSpace(str2);
        System.out.println(str1);
        sc.close();

    }
    public static String replaceSpace(StringBuffer str) {
        //首先将字符串扩容有多少个空格就在末尾加上三倍的空位
        //使用append函数在末尾进行添加
        int  b=str.length()-1;
        for (int i=0;i<=b;i++){
            if (str.charAt(i)==' ')
            str.append("  "); 
        }
        int a=str.length()-1;
        //双指针从新开数组的末位进行添加
        while(b>=0&&a>b){
            char c=str.charAt(b--);
            if (c==' '){
                str.setCharAt(a--, '0');
                str.setCharAt(a--, '2');
                str.setCharAt(a--, '%');
            }
            else str.setCharAt(a--, c);
        }
     
        return str.toString();
    }
}

/* 
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，
当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */


