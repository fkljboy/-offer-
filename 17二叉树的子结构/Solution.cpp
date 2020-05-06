class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
    bool result = false;
        if(pRoot1 != NULL && pRoot2 != NULL){
            if(pRoot1->val == pRoot2->val){
            result = DoesTree1HasTree2(pRoot1, pRoot2);
        }
            if(!result){
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            if(!result){
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }
        return result;
    }
private:
    bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL){
            return true;
        }
        if(pRoot1 == NULL){
            return false;
        }
        if(pRoot1->val != pRoot2->val){
            return false;
        }
        return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
    }
};
/* 首先需要找到一个两树相同的根节点，然后就写一个函数来判断是不是子结构
所以这里需要两个递归，第一个递归是遍历a树的每一个根节点，寻找和b树的
某个根节点相同的位置，寻找到以后还需要在判断函数内递归判断两个根节点
下面的子树是不是相等 */