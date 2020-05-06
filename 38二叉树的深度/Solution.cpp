/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* root)
    {
        return root == NULL ? 0 : 1 + max(TreeDepth(root->left), TreeDepth(root->right));
    }
};
// 先递归到最底层 然后在逐级返回并加1