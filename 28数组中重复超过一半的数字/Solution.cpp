class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int,int>  num;
        int len =numbers.size();
        for (int i=0;i<len;i++){
            num[numbers[i]]++;
        }
        for (auto &v:num){
            if (v.second>len/2)
                return v.first;
        }
        return 0;
    }
};
/* 这个题用容器做就可以了，可以用map也可以用set，只要在
将所有的数字全部存入以后对数字进行统计就可以了，好在
map和set都存在统计的功能，map是通过键值对的更新统计
set可以通过其count函数进行统计。 */