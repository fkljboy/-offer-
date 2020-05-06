class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (input.empty()||k>input.size()){
            return res;
        }
        sort(input.begin(),input.end());
        for (int i=0;i<k;i++){
            res.push_back(input[i]);
        }
        return res;
    }
};
// 排序输出

 public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        if (input==null||input.length==0||input.length<k||k<=0) {
            return res;
        }
 
        int start  = 0;
        int end = input.length-1;
        int index = partition(input, start, end);
        //一直循环知道找到第k个位置正确的数。
        while (index != k - 1) {
            if (index > k - 1) {
                end = index-1;
                index = partition(input, start, end);
            } else {
                start = index+1;
                index = partition(input, start, end);
            }
 
        }
 
        for (int i = 0; i < k; i++) {
            res.add(input[i]);
        }
 
        return res;
    }
 
   static int partition(int input[], int start, int end) {
        int tmp = input[start];
        while (start < end) {
            while (start < end && input[end] >= tmp) {
                end--;
            }
            input[start] = input[end];
            while (start < end && tmp >= input[start]) {
                start++;
            }
            input[end] = input[start];
        }
        input[start] = tmp;
        return start;
    }

    /* 方法二是利用快排思想解决该问题，快排是解决此问题时间复杂度最低的一种
    思路，首先通过一轮快排得到一个基准数，然后对该基准数的位置和k进行比较
    如果大于则对前半部分进行下一轮快排，否则就对后半部分进行下一轮快排 */