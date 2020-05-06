class Solution {
private:
    stack<int> stackData;
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size()==0) return false;
        for (int i=0,j=0;i<pushV.size();i++){
            stackData.push(pushV[i]);
            while (j<popV.size()&&stackData.top()==popV[j]){
                stackData.pop();
                j++;
            }
        }
        return stackData.empty();
    }
};
/* 完全去模拟入栈的出栈的过程，切这两个过程需要同时进行，压入一个然后
判断压入的数是不是等于弹出序列的第一个数，如果符合则弹出 否则就跳过
因为压的次数是等于弹的次数的，所以如果是合法的弹出序列的话那么最后一定
会得到一个空栈，否则就不是该压入序列的一个合法弹出序列
 */