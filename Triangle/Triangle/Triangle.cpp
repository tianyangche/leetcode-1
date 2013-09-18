#include "Triangle.h"


Triangle::Triangle(void)
{
}

int Triangle::minimumTotal(vector<vector<int> > &triangle) {
	if (triangle.empty())
		return 0;
	int n = triangle.size();
	for (int i = n - 2; i >= 0; i--) {
		int m = triangle[i].size();
		for (int j = 0; j < m; j++) {
			triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
		}
	}
	return triangle[0][0];
}

Triangle::~Triangle(void)
{
}
