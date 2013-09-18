#include "ZigzagLevelOrder.h"


ZigzagLevelOrder::ZigzagLevelOrder(void)
{
}

vector<vector<int> > ZigzagLevelOrder::zigzaglevelOrder(TreeNode *root) {
	vector<vector<int> > result;
	if (root == NULL)
		return result;
	vector<TreeNode*> nodes;
	nodes.push_back(root);
	zigzaglevelOrder(nodes, result, true);
	return result;
}

void ZigzagLevelOrder::zigzaglevelOrder(vector<TreeNode*> nodes, vector<vector<int> > &result, bool order) {
	if (nodes.size() != 0) {
		vector<TreeNode*> newNodes;
		vector<int> newRow;
		int size = nodes.size();
		for (vector<TreeNode*>::iterator i = nodes.begin(); i != nodes.end(); i++) {
			if ((*i)->left != NULL)
				newNodes.push_back((*i)->left);
			if ((*i)->right != NULL)
				newNodes.push_back((*i)->right);
			newRow.push_back((*i)->val);
		}
		if (!order) {
			int rowSize = newRow.size();
			int n		= rowSize / 2;
			int temp;
			for (int i = 0; i < n; i++) {
				temp = newRow[i];
				newRow[i] = newRow[rowSize-i-1];
				newRow[rowSize-i-1] = temp;
			}
		}
		result.push_back(newRow);
		if (newNodes.size() != 0)
			zigzaglevelOrder(newNodes, result, !order);
	}
}

ZigzagLevelOrder::~ZigzagLevelOrder(void)
{
}
