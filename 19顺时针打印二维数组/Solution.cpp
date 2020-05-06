class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int>  res;
        int r1=0,r2=matrix.size()-1,c1=0,c2=matrix[0].size()-1;
        while (r1<=r2&&c1<=c2){
            for (int i=c1;i<=c2;i++){
                res.push_back(matrix[r1][i]);
            }
            for (int i=r1+1;i<=r2;i++){
                res.push_back(matrix[i][c2]);
            }
            if (r1!=r2){
                for (int i=c2-1;i>=c1;i--){
                    res.push_back(matrix[r2][i]);
                }
            }
            if (c1!=c2){
                for (int i=r2-1;i>r1;i--){
                    res.push_back(matrix[i][c1]);
                }
            }
            r1++;r2--;c1++;c2--;
        }
        return res;
    }
};
/* 思路简单暴力，首先通过四个部分将最外圈打印完，然后判断上下的指针
是否相等来判断是否已经打印完 */