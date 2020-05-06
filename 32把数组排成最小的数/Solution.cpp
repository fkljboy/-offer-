class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int len =numbers.size();
        string res;
        if(len==0) return "";
        sort(numbers.begin(),numbers.end(),cmp);
        for (int i=0;i<len;i++){
            res+=to_string(numbers[i]);
         }
        return res;
    }
private:
    static bool cmp(int a,int b){
        string ab=to_string (a)+to_string (b);
        string ba=to_string (b)+to_string (a);
        return ab<ba;
        
    }
};
/* 定义一个排序规则函数，将该函数作为参数传入主函数的sort中
逐个比较即可 */