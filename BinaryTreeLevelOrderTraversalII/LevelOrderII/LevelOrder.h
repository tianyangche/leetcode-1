#pragma once
#include <stddef.h>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class LevelOrder
{
public:
	LevelOrder(void);
	vector<vector<int> > levelOrder(TreeNode *root);
	void levelOrder(vector<TreeNode*> nodes, vector<vector<int> > &result);
	~LevelOrder(void);
};

