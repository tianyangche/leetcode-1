/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
        	return NULL;
        map<int, UndirectedGraphNode*> recs;
        return cloneGraph(node, recs);
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode* node, map<int, UndirectedGraphNode*> &recs) {
    	if (node == NULL)
    		return NULL;
        if (recs.count(node->label) > 0)
        	return recs[node->label];
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        recs[node->label] = copy;
        for (int i = 0; i < node->neighbors.size(); i++) {
        	UndirectedGraphNode *neighbor = cloneGraph(node->neighbors[i], recs);
        	copy->neighbors.push_back(neighbor);
        }
        return copy;
    }
};