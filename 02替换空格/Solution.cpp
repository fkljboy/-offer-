/* 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，
当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。 */
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int i = 0;
        int numSpace =0;
        // 通过这一步获得数组的长度和空格的数量
        while(str[i] != '\0')
            {
            if(str[i]==' ')
                numSpace++;
            ++i;
        }
        //定义新数组的长度，并建立双指针
        int newLen = i+numSpace*2;
        for(int j=i;j>=0,newLen>=0;)
        {
            if(str[j]==' ')
                {
                str[newLen--] = '0';
                str[newLen--] = '2';
                str[newLen--] = '%';
            }
            else
                str[newLen--] = str[j];
            j--;
        }
    }
};