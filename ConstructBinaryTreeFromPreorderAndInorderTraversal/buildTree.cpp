struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(X), left(NULL), right(NULL) {}
}

class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.empty() && inorder.empty())
			return NULL;
		TreeNode *headNode = (TreeNode *)malloc(sizeof(TreeNode));
		headNode->left  = NULL;
		headNode->right = NULL;
		buildTree(headNode, preorder.begin(), inorder.begin(), preorder.size());
		return headNode;
	}

	void buildTree(TreeNode *node, vector<int>::iterator preorder, vector<int>::iterator inorder, int size) {
		if (size == 1) {
			node->val = *preorder;
		} else {
			node->val = *preorder;
			vector<int>::iterator iter = find(inorder, inorder+size, node->val);
			int n = iter - inorder;
			if (n != 0) {
				TreeNode *leftNode = (TreeNode *)malloc(sizeof(TreeNode));
				leftNode->left  = NULL;
				leftNode->right = NULL;
				node->left = leftNode;
				buildTree(leftNode, preorder+1, inorder, n);
			}
			if (size - n - 1 != 0) {
				TreeNode *rightNode = (TreeNode *)malloc(sizeof(TreeNode));
				rightNode->left  = NULL;
				rightNode->right = NULL;
				node->right = rightNode;
				buildTree(rightNode, preorder+1+n, inorder+1+n, size-n-1);
			}
		}
	}
};