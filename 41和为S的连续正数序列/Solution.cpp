class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        int high=2,low=1;
        while (high>low){
           int curSum=(low+high)*(high-low+1)>>1;
            if (curSum<sum){
                high++;
            }
            if (curSum==sum){
                vector<int> temp;
                for (int i=low;i<=high;i++){
                    temp.push_back(i);
                }
                result.push_back(temp);
                low++;
            }
            if (curSum>sum){
                low++;
            }
        }
        return result;
    }
};
/* 这题妥妥的双指针，然后利用等差数列的求和公式，不断去更新先后指针
的值，就可以得到所有的需要的值。 */