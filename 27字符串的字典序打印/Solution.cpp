class Solution {

    
public:
    vector<string> Permutation(string str) {
        if(str.size()==0){
            return result;
        }
        PermutationC(str,0);
        sort(result.begin(),result.end());
        return result;
    }
private :
    vector<string> result ;
    void PermutationC(string str,int begin){
    //递归 结束的条件
    if (begin==str.size()){
        result.push_back(str);
        return;
    }
    for(int i=begin;i<str.size();i++){
        if (i!=begin&&str[begin]==str[i]) continue;
        swap(str[begin],str[i]);
        PermutationC(str,begin+1);
    }
}
};
/* 交换递归思路，现将第一个字符和后面所有的字符分别交换 得到若干种情况
然后再将交换后的数组进入递归，使第二个字符和后面的每一个字符交换
再递归，递归结束的条件是交换到了最后，则得到了一种结果，最后将
所有结果存入result中排序即可 */