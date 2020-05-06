class Solution {
public:
    void reOrderArray(vector<int> &array) {
        deque<int>  res;
        int len =array.size()-1;
        for (int i=0;i<=len;i++){
            if (array[len-i]%2==1) 
                res.push_front(array[len-i]);
            if(array[i]%2==0)
                res.push_back(array[i]);
        }
        array.assign(res.begin(),res.end());
    }
};
/* 使用双向队列，遍历数组，如果是奇数则头插，如果是偶数则尾插
但是需要注意的是，双指针中，奇数遍历指针要从数组尾部开始而
偶数遍历指针要从数组头部开始，这样才能保证奇偶数重排后的相对
位置不变 时间复杂度小而空间复杂度大*/