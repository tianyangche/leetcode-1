class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        char** map = (char**)malloc(n*sizeof(char*));
        for (int i = 0; i < n; i++) {
            map[i] = (char*)malloc(n*sizeof(char));
        }
        int* row = (int*)malloc(n*sizeof(int));
        for (int i = 0; i < n; i++)
            row[i] = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = '.';
            }
        }
        int col = 0;
        while (col < n) {
            map[0][col] = 'Q';
            row[0] = col;
            findQueen(map, row, 1, n, res);
            map[0][col] = '.';
            row[0] = -1;
            col++;
        }
        return res;
    }

    void findQueen(char** map, int* row, int num, int n, vector<vector<string> > &res) {
        if (num == n) {
            vector<string> newMap;
            for (int i = 0; i < n; i++) {
                string newRow;
                for (int j = 0; j < n; j++) {
                    newRow.push_back(map[i][j]);
                }
                newMap.push_back(newRow);
            }
            res.push_back(newMap);
        } else {
            for (int col = 0; col < n; col++) {
                if (isValid(row, num, col, n)) {
                    row[num] = col;
                    map[num][col] = 'Q';
                    findQueen(map, row, num+1, n, res);
                    row[num] = -1;
                    map[num][col] = '.';
                }
            }
        }
    }

    bool isValid(int* row, int i, int j, int n) {
        for (int k = 0; k < i; k++) {
            if (row[k] == j || abs(row[k]-j) == abs(i-k))
                return false;
        }
        return true;
    }
};