class Solution {
public:
    string LeftRotateString(string str, int n) {
        string result = str;
        int length = result.size();
        if(length < 0){
            return NULL;
        }
        if(0 <= n <= length){
            int pFirstBegin = 0, pFirstEnd = n - 1;
            int pSecondBegin = n, pSecondEnd = length - 1;
            ReverseString(result, pFirstBegin, pFirstEnd);
            ReverseString(result, pSecondBegin, pSecondEnd);
            ReverseString(result, pFirstBegin, pSecondEnd);
        }
        return result;
    }
private:
    void ReverseString(string &str, int begin, int end){
        while(begin < end){
            swap(str[begin++], str[end--]);
        }
    }
};
// 先将数组的前n个元素逆置，然后把后n个元素逆置，最后在全体逆置