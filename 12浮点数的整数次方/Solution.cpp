class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent==1){
            return base;
        }
        if (exponent==0){
            return 1;
        }
        bool flag=false;
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
};