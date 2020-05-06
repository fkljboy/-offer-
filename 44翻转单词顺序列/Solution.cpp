class Solution {
public:
    string ReverseSentence(string str) {
        string result =str;
        int len=result.size();
        if(len==0) return "";
        result +=' ';
        int mark=0;
        for (int i=0;i<len+1;i++){
            if(result[i]==' '){
                reverse(result,mark,i-1);
                mark=i+1;
            }
        }
            result=result.substr(0,len);
            reverse(result,0,len-1);
            return result;
            
        }
private :
        void reverse(string &str,int begin,int end){
            while(begin<end){
                swap(str[begin++],str[end--]);
            }
        }
};
// 以空格为界，先将所有的单词全部逆序，然后在整体逆序回来即可