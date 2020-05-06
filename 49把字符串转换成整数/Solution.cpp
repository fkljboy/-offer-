class Solution {
public:
    enum Status{kValid = 0, kInValid};
    int g_nStatus = kValid;
    int StrToInt(string str) {
        g_nStatus = kInValid;
        long long num = 0;
      
        const char* cstr = str.c_str();
        // 判断是否为指针和是否为空字符串
        if(cstr != NULL && *cstr != '\0'){
            // 正负号标志位，默认是加号
            bool minus = false;
            if(*cstr == '+'){
                cstr++;
            }
            else if(*cstr == '-'){
                minus = true;
                cstr++;
            }
            if(*cstr != '\0'){
                num = StrToIntCore(cstr, minus);
            }
        }
        return (int)num;
    }
private:
    long long StrToIntCore(const char* cstr, bool minus){
        long long num = 0;
        while(*cstr != '\0'){
            // 判断是否是非法值
            if(*cstr >= '0' && *cstr <= '9'){
                int flag = minus ? -1 : 1;
                num = num * 10 + flag * (*cstr - '0');
                // 判断是否溢出,32位
                if((!minus && num > 0x7fffffff) || (minus && num < (signed int)0x80000000)){
                    num = 0;
                    break;
                }
                cstr++;
            }
            else{
                num = 0;
                break;
            }
        }
        // 判断是否正常结束
        if(*cstr == '\0'){
            g_nStatus = kValid;
        }
        return num;
    }
};
/* 把字符串的每一个元素提取出来，乘就好了 就是需要判定异常值和越界值，
这个题牛客上怎么搞都是85% 我哭了 */