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

class ZigzagLevelOrder
{
public:
	ZigzagLevelOrder(void);
	vector<vector<int> > zigzaglevelOrder(TreeNode *root);
	void zigzaglevelOrder(vector<TreeNode*> nodes, vector<vector<int> > &result, bool order);
	~ZigzagLevelOrder(void);
};

