class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        multiset<int> a;
        int flag=0;
        for (int i=0;i<length;i++){
            if (a.count(numbers[i])==0){
                a.insert(numbers[i]);
            }
            else {
                duplication[0]=numbers[i];
                flag=1;
                break;
            }
        }
        if(flag==1)
        return duplication;
        else return false;
    }
};
这个题用multiset做比较合理，如果count为0就添加进去，如果count为1就说明
/* 找到了，直接返回就好了 */