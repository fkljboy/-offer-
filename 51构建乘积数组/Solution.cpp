class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len=A.size();
        vector<int> B(len);
        if (len<=0) return B;
        B[0]=1;
        for (int i=1;i<len;i++){
            B[i]=B[i-1]*A[i-1];
        }
        int temp=1;
        for(int i=len-2;i>=0;i--){
            temp=temp*A[i+1];
            B[i]=B[i]*temp;
        }
        return B;
    }
};
/* 把原数组分为两部分，a[i]之前的部分和a[i]之后的部分，之前的部分
通过累乘可以得到，后面的部分也是通过一个temp来记录累乘的值
然后再和b[i]相乘 */