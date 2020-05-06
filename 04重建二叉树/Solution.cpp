/* 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。 */
 

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {

        if(pre.size() == 0){                    //如果为空，返回NULL
            return NULL;
        }
        //依次是前序遍历左子树，前序遍历右子树，中序遍历左子树，中序遍历右子树
        vector<int> left_pre, right_pre, left_vin, right_vin;
        //前序遍历第一个节点一定为根节点
        TreeNode* head = new TreeNode(pre[0]);
        //找到中序遍历的根节点
        int root = 0;
        //遍历找到中序遍历根节点索引值
        for(int i = 0; i < pre.size(); i++){
            if(pre[0] == vin[i]){
                root = i;
                break;
            }
        }
           //利用中序遍历的根节点，对二叉树节点进行归并
        for(int i = 0; i < root; i++){
            left_vin.push_back(vin[i]);
            left_pre.push_back(pre[i + 1]);            //前序遍历第一个为根节点
        }
        
        for(int i = root + 1; i < pre.size(); i++){
            right_vin.push_back(vin[i]);
            right_pre.push_back(pre[i]);
        }
        
        //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
        head->left = reConstructBinaryTree(left_pre, left_vin);
        head->right = reConstructBinaryTree(right_pre, right_vin);
        return head;
    }
};
/* 这道题的实现还是比较复杂的,但是思路很清晰，就是对二叉树按前序和中序进行拆解
拆解的实现在于首先把他们拆解成四个分数组，然后将四个分数组分别代入递归中
即可继续拆解 */