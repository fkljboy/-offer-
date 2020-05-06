//num1,num2分别为长度为1的数组。传出参数
//将num1[0],num2[0]设置为返回结果
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
          multiset<int> a;
          int len=data.size();
          for(int i=0;i<len;i++){
              a.insert(data[i]);
          }
        int num=0;
        for (int i=0;i<len;i++){
            if (a.count(data[i])==1)
            {
                num++;
                if (num==1)  {
                *num1=data[i];
                continue;
            } 
            if (num==2)  {
                *num2=data[i];
                break;
            }
            }
            
        }
    }
};
/* 用可以存在重复数据的multiset也可以解决这个问题，但时间复杂度和
空间复杂度会差一些 */