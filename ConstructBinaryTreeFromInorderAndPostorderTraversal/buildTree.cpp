struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    	if (inorder.empty() && postorder.empty())
            return NULL;
        TreeNode *headNode = (TreeNode *)malloc(sizeof(TreeNode));
		headNode->left  = NULL;
		headNode->right = NULL;
		buildTree(headNode, inorder.begin(), postorder.begin(), inorder.size());
		return headNode;
	}

	void buildTree(TreeNode *node, vector<int>::iterator inorder, vector<int>::iterator postorder, int size) {
		if (node != NULL && size != 0) {
			if (size == 1) {
				node->val = *inorder;
			} else {
				node->val = *(postorder+size-1);
				vector<int>::iterator iter = find(inorder, inorder+size, node->val);
				int leftSize = iter - inorder;
				if (leftSize != 0) {
					TreeNode *leftNode = (TreeNode *)malloc(sizeof(TreeNode));
					leftNode->left  = NULL;
					leftNode->right = NULL;
					node->left = leftNode;
					buildTree(leftNode, inorder, postorder, leftSize);
				}
				if (size - leftSize - 1 != 0) {
					TreeNode *rightNode = (TreeNode *)malloc(sizeof(TreeNode));
					rightNode->left  = NULL;
					rightNode->right = NULL;
					node->right = rightNode;
					buildTree(rightNode, inorder+leftSize+1, postorder+leftSize, size-leftSize-1);
				}
			}
		}
	}
};