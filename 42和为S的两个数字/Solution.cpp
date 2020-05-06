class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        int len =array.size();
        int l=0,h=len-1;
        while (l<h){
            if (sum==array[l]+array[h]){
                result.push_back(array[l]);
                result.push_back(array[h]);
                break;
            }
            else if (sum>array[l]+array[h]) l++;
            else h--;
        }
        return result;
    }
};
/* 双指针，一个在头一个在尾，而且乘积来看外面的两个数相乘一点小于里面的
类似于同样的周长的矩形面积，正方形最大。 */