
class Solution {
public:
    int searchfirst(int num, vector<int>& vec){
        int begin = 0;
        int end = vec.size()-1;
        int middle;
        while(begin < end - 1){
            middle = begin+(end-begin)/2;
            if(vec[middle] >= num){
                end = middle;
            }else
                begin = middle;
        }
        if(vec[begin] == num) return begin;
        else return end;
 }
 
 int searchback(int num, vector<int>& vec){
        int begin = 0;
        int end = vec.size()-1;
        int middle;
        while(begin < end - 1){
            middle = begin+(end-begin)/2;
            if(vec[middle] > num){
                end = middle;
            }else
                begin = middle;
        }
        if(vec[end] == num) return end;
        else return begin;

 }
  int GetNumberOfK(vector<int> data ,int k) {
        int length = data.size();
        if(length == 0){
            return 0;
        }
        int first = searchfirst(k,data);
        int last = searchback(k, data);
        if(first != -1 && last != -1){
            return last - first + 1;
        }
        return 0;
    }
}
/* 这道题时间复杂度最优的方法一定是二分，这就涉及到二分的一个进阶
就是寻找重复目标数的第一个和最后一个位置，区别在于第一个则在找
middle前找到时，不跳出，继续找，最后一个是在middle后找到时，不跳出
继续找 */