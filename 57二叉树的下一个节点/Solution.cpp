/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode==NULL) return NULL;
        TreeLinkNode* pNext=NULL;
        if (pNode->right!=NULL){
            TreeLinkNode* pRight =pNode->right;
            while (pRight->left!=NULL){
                pRight=pRight->left;
            }
            pNext=pRight;
        }
        else if (pNode!=NULL){
            TreeLinkNode* pCur=pNode;
            TreeLinkNode* pPar=pNode->next;
            while(pPar!=NULL&&pCur!=pPar->left){
                pCur=pPar;
                pPar=pPar->next;
            }
            pNext=pPar;
        }
        return pNext;
    }
};
/* 要分为两种情况，第一种情况是该节点存在右节点的情况，这是需要对
它的右节点进行深挖，挖出这个右节点最末端的左节点（中序遍历的规则）
第二种情况就是该节点不存在右节点的情况，这时它的下一个节点肯定在上面
所以要向上找到第一个是母节点的左节点的节点，即为中序遍历的下一个节点 */