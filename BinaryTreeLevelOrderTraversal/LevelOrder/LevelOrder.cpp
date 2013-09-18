#include "LevelOrder.h"


LevelOrder::LevelOrder(void)
{
}

vector<vector<int> > LevelOrder::levelOrder(TreeNode *root) {
	vector<vector<int> > result;
	if (root == NULL)
		return result;
	vector<TreeNode*> nodes;
	nodes.push_back(root);
	levelOrder(nodes, result);
	return result;
}

void LevelOrder::levelOrder(vector<TreeNode*> nodes, vector<vector<int> > &result) {
	if (nodes.size() != 0) {
		vector<TreeNode*> newNodes;
		vector<int> newRow;
		for (vector<TreeNode*>::iterator i = nodes.begin(); i != nodes.end(); i++) {
			if ((*i)->left != NULL)
				newNodes.push_back((*i)->left);
			if ((*i)->right != NULL)
				newNodes.push_back((*i)->right);
			newRow.push_back((*i)->val);
		}
		result.push_back(newRow);
		if (newNodes.size() != 0)
			levelOrder(newNodes, result);
	}
}

LevelOrder::~LevelOrder(void)
{
}
