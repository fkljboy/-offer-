class Solution {
public:
    void Insert(int num)
    {
        // 如果已有数据为偶数，则放入最小堆
        if(((max.size() + min.size()) & 1) == 0){
            // 如果插入的数字小于最大堆里的最大的数，则将数字插入最大堆
            // 并将最大堆中的最大的数字插入到最小堆
            if(max.size() > 0 && num < max[0]){
                // 插入数据插入到最大堆数组
                max.push_back(num);
                // 调整最大堆
                push_heap(max.begin(), max.end(), less<int>());
                // 拿出最大堆中的最大数
                num = max[0];
                // 删除最大堆的栈顶元素
                max.pop_back();
                // 调整最大堆
                pop_heap(max.begin(), max.end(), less<int>());
                
            }
            // 将数据插入最小堆数组
            min.push_back(num);
            // 调整最小堆
            push_heap(min.begin(), min.end(), greater<int>());
        }
        // 已有数据为奇数，则放入最大堆
        else{
            //同理如果该数大于最小堆的最小值，就把它放进最小堆
            if(min.size() > 0 && num > min[0]){
                // 将数据插入最小堆
                min.push_back(num);
                // 调整最小堆
                push_heap(min.begin(), min.end(), greater<int>());
                // 拿出最小堆的最小数
                num = min[0];
                // 删除最小堆的栈顶元素
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            // 将数据插入最大堆
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian()
    { 
         int size = min.size() + max.size();
        if(size == 0){
            return 0;
        }
        // 如果数据为偶数
        if((size & 1) == 0){
            return (min[0] + max[0]) / 2.0;
        }
        // 奇数
        else{
            return min[0];
        }
    }
    private:
    // 使用vector建立最大堆和最小堆,min是最小堆数组,max是最大堆数组
    vector<int> min;
    vector<int> max;

};
/* 用大顶堆和小顶堆吧数据分为两部分，大顶堆最大的数小于小顶堆最小的数
这样取中位数的时候就是大小顶堆的顶点相加除二或者在奇数情况时直接取
小顶堆的顶点，这里需要保证的是大小顶堆的长度差不能超过1，要按奇偶
交替插入 */