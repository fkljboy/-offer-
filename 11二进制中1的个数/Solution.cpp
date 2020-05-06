class Solution {
public:
     int  NumberOf1(int n) {
         int sum=0;
         while(n!=0){
             n &=(n-1);
             sum++;
         }
         return sum;
     }
};
/* 先做减一运算，就可以使二进制数字中的第一个1变成零，同时后面的0都变成1，然后
与上次得到的数字做与运算，就可以将第一个1以及后面的数字全部置零，知道
二进制的所有位全部变成0 */