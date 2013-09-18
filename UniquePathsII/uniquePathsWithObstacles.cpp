class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
 		if (obstacleGrid.empty())
 			return 0;
 		vector<vector<int> > map;
 		vector<int> temp;
 		for (int i = 0; i < obstacleGrid[0].size(); i++) {
 			temp.push_back(0);
 		}
 		for (int i = 0; i < obstacleGrid.size(); i++) {
 			map.push_back(temp);
 		}
 		if (obstacleGrid[0][0] == 0)
 			map[0][0] = 1;
 		for (int i = 0; i < obstacleGrid.size(); i++) {
 			for (int j = 0; j < obstacleGrid[i].size(); j++) {
 				if (obstacleGrid[i][j] == 0) {
 					if (i > 0)
 						map[i][j] += map[i-1][j];
 					if (j > 0)
 						map[i][j] += map[i][j-1];
 				}
 			}
 		}
 		return map[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
	}
};