class Solution {
public:
   public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return bst(sequence, 0, sequence.size() - 1);
    }
private:
    bool bst(vector<int> seq, int begin, int end){
        if(seq.empty() || begin > end){
            return false;
        }
        
        //根结点
        int root = seq[end];
        
        //在二叉搜索树中左子树的结点小于根结点
        int i = begin;
        for(; i < end; ++i){
            if(seq[i] > root){
                break;
            }
        }
        
        //在二叉搜索书中右子树的结点大于根结点
        for(int j = i; j < end; ++j){
            if(seq[j] < root){
                return false;
            }
        }
        
        //判断左子树是不是二叉搜索树
        bool left = true;
        if(i > begin){
            left = bst(seq, begin, i - 1);
        }
        
        //判断右子树是不是二叉搜索树
        bool right = true;
        if(i < end - 1){
            right = bst(seq, i , end - 1);
        }
        
        return left && right;
    }
};
/* 拿到这个题 首先你需要做的是画一个搜索树出来去分析一波，可以得出的结论是
对于一个后续遍历来说，数组的最后一个值就是根节点，然后对于一个二叉搜索树
来说，他的左子树的每一个值都小于根节点而右子树的每一个值都大于他的根节点
这样的话，我们只需要去找到最后一个小于数组最后一个值的数组元素，即为二叉树
的左子结点，而数组末尾的前一个数字即为二叉树的右子节点，这是进入递归，
递归中需要判断的重点就是是不是符合搜索二叉树的原则，左小于中小于右即可 */