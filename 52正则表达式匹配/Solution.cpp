链接：https://www.nowcoder.com/questionTerminal/45327ae22b7b413ea21df13ee7d6429c?answerType=1&f=discussion
来源：牛客网

class Solution {
public:
    bool isMatch(string s, string p) {
        s = " " + s;//防止该案例：""\n"c*"
        p = " " + p;
        //可以少一部分初始化
        int m = s.size(), n = p.size();
        bool dp[m + 1][n + 1];
        memset(dp, false, (m + 1) * (n + 1));
        dp[0][0] = true;//长度为0一定是匹配的
        for (int i = 1; i <= m; i++) {//枚举两个字符串的长度
            for (int j = 1; j <= n; j++) {//dp的意思是s长度为i,p长度为j是否匹配
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    //如果两个字符相等或者p是点就同时匹配两个
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    //如果是*
                    if (s[i - 1] != p[j - 2] && p[j - 2] != '.')
                        //二者不相等的时候，就将这个*和前面的字符都跳过去看是否匹配
                        dp[i][j] = dp[i][j - 2];
                    else {
                        //二者相等的时候,可以选择跳过或者选一个或多个
                        dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
                        // dp[i][j] = dp[i-1][j]  多个字符匹配的情况    
                        //or dp[i][j] = dp[i][j-1]  单个字符匹配的情况
                        //or dp[i][j] = dp[i][j-2]  没有匹配的情况    
                    }
                }
            }
        }
        return dp[m][n];
    }
};
/* 动态规划解法应该是最快的，但是比较难理解 */