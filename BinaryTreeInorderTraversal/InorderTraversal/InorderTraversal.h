#pragma once
#include <stddef.h>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class InorderTraversal
{
public:
	InorderTraversal(void);
	vector<int> inorderTraversal(TreeNode *root);
	void inorderTraversal(TreeNode *root, vector<int> &result);
	~InorderTraversal(void);
};

