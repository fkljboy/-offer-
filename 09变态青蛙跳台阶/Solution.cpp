/* 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。 */

class Solution {
public:
    int jumpFloorII(int number) {
        if (number==1){
            return 1;
        }
          int a[number];
        for (int i=0;i<number;i++){
            a[i]=1;
        } 
       // memset(a,1,sizeof(a));
        for (int i=1;i<number;i++){
            for(int j=0;j<i;j++){
                a[i]+=a[j];
            }
        }
        return a[number-1];
    }
};
/* 这个可以用数学归纳法  也可以将用动态规划 思路是将所有元素置1
然后进行累加，这里需要指出一个语法问题 就是memset
一个int是4个字节的，8个int是32个字节，所以首先要赋值的长度就不应该为8而是32。
因为memset是 逐字节 拷贝，以num为首地址的8字节空间都被赋值为1，
即一个int变为0X00000001 00000001 00000001 00000001，显然，把这个数化为十进制不会等于1的。
所以，在memset使用时要千万小心，在给char以外的数组赋值时，只能初始化为0或者-1。 */