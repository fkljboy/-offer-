class Solution {
public:
    bool isNumeric(char* string)
    {
         // 指针为空，返回false
       // 非法输入处理
        if(string == NULL || *string == '\0'){
            return false;
        }
        // 正负号判断
        if(*string == '+' || *string == '-'){
            ++string;
        }
        bool numeric = true;
        scanDigits(&string);
        if(*string != '\0'){
            // 小数判断
            if(*string == '.'){
                ++string;
                scanDigits(&string);
                if(*string == 'e' || *string == 'E'){
                    numeric = isExponential(&string);
                }
            }
            // 整数判断
            else if(*string == 'e' || *string == 'E'){
                numeric = isExponential(&string);
            }
            else{
                numeric = false;
            }
        }
        return numeric && *string == '\0';
    }
private:
    // 扫描数字，对于合法数字，直接跳过
    void scanDigits(char** string){
        while(**string != '\0' && **string >= '0' && **string <= '9'){
            ++(*string);
        }
    }
    // 用来潘达un科学计数法表示的数值的结尾部分是否合法
    bool isExponential(char** string){
        ++(*string);
        if(**string == '+' || **string == '-'){
            ++(*string);
        }
        if(**string == '\0'){
            return false;
        }
        scanDigits(string);
        // 判断是否结尾，如果没有结尾，说明还有其他非法字符串
        return (**string == '\0') ? true : false;
    }

};