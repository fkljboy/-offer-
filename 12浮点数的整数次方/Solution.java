
public class Solution {
    double Power(double base, int exponent) {
        if (exponent==1){
            return base;
        }
        if (exponent==0){
            return 1;
        }
        boolean flag=false;
        if (exponent<0){
            exponent=-exponent;
            flag=true;
        }
        double res=Power(base*base,exponent/2);
        if (exponent%2!=0){
            res=base*res;
        }
        return flag?1/res:res;
    }
}
/* 当指数为负数的时候，可以先对指数求绝对值，然后算出次方的结果之后再取倒数。
如果底数为0，则直接返回0。此时的次方在数学上是没有意义的。 */
