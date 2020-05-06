class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        
        //用于记录双向链表尾结点
        TreeNode* pLastNodeInList = NULL;
        
        //开始转换结点
        ConvertNode(pRootOfTree, &pLastNodeInList);
        
        //pLastNodeInList指向双向链表的尾结点，我们需要重新返回头结点
        TreeNode* pHeadOfList = pLastNodeInList;
        while(pHeadOfList != NULL && pHeadOfList->left != NULL){
            pHeadOfList = pHeadOfList->left;
        }
        return pHeadOfList;
    }
    
    void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList){
        //叶结点直接返回
        if(pNode == NULL){
            return;
        }
        TreeNode* pCurrent = pNode;
        //递归左子树
        if(pCurrent->left != NULL)
            ConvertNode(pCurrent->left, pLastNodeInList);
        
        //左指针
        pCurrent->left = *pLastNodeInList;
        //右指针
        if(*pLastNodeInList != NULL){
            (*pLastNodeInList)->right = pCurrent;
        }
        //更新双向链表尾结点
        *pLastNodeInList = pCurrent;
        //递归右子树
        if(pCurrent->right != NULL){
            ConvertNode(pCurrent->right, pLastNodeInList);
        }
    }
};
这题思路还是比较明确的，就是实现起来很麻烦，需要严格按照中序遍历的思路去
完成，也就是先递归左子树，再将左子树和根节点相连，在递归右子树，好麻烦
不想做了。。。。