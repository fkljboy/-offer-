class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
         vector<int> maxInWindows;
        // 数组大小要大于等于窗口大小，并且窗口大小大于等于1
        if(num.size() >= size && size >= 1){
            deque<int> index;
            for(unsigned int i = 0; i < size; i++){
                // 如果index非空，并且新添加的数字大于等于队列中最小的数字，则删除队列中最小的数字
                while(!index.empty() && num[i] >= num[index.back()]){
                    index.pop_back();
                }
                index.push_back(i);
            }
            for(unsigned int i = size; i < num.size(); i++){
                maxInWindows.push_back(num[index.front()]);
                while(!index.empty() && num[i] >= num[index.back()]){
                    index.pop_back();
                }
                // 控制窗口大小为size
                if(!index.empty() && index.front() <= int(i - size)){
                    index.pop_front();
                }
                index.push_back(i);
            }
            maxInWindows.push_back(num[index.front()]);
        }
        return maxInWindows;
    }
};
/* 第一个for循环，把第一个滑动窗口的东西存进去，然后如果后面的比前面的大
就弹出前面的，这样就可以保证窗口的最大值永远在队首，然后第二个for循环
开始添加剩余的数，同样的操作，但是后面需要加一个控制窗口大小的判断，
删除窗口以外的数字，最后在压入新的数字 */