class Solution {
public:
    int GetUglyNumber_Solution(int index) {
     if(index < 7){
            return index;
        }
        vector<int> res(index);
        for(int i = 0; i < 6; i++){
            res[i] = i + 1;
        }
        int t2 = 3, t3 = 2, t5 = 1;
        for(int i = 6; i < index; i++){
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            while(res[i] >= res[t2] * 2){
                t2++;
            }
            while(res[i] >= res[t3] * 3){
                t3++;
            }
            while(res[i] >= res[t5] * 5){
                t5++;
            }
        }
        return res[index - 1];
    }
};
/* 实际上这是动态规划的思想，首先我们可以知道的是所有的丑数都可以用已知的
前六个丑数乘2，乘3，乘5得到，而且必然会依次递增，这样我们只需要不断更新
乘数，同时保存结果作为行的乘数即可 */