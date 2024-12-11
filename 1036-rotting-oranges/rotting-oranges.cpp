class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
            }
        }

        int ans = 0;

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;

            q.pop();
            ans = max(time, ans);

            if (row + 1 < m && grid[row + 1][col] == 1 && visited[row + 1][col] != 2) {
                visited[row + 1][col] = 2;
                q.push({{row + 1, col}, time + 1});
            }
            if (row - 1 >= 0 && grid[row - 1][col] == 1 && visited[row - 1][col] != 2) {
                visited[row - 1][col] = 2;
                q.push({{row - 1, col}, time + 1});
            }
            if (col + 1 < n && grid[row][col + 1] == 1 && visited[row][col + 1] != 2) {
                visited[row][col + 1] = 2;
                q.push({{row, col + 1}, time + 1});
            }
            if (col - 1 >= 0 && grid[row][col - 1] == 1 && visited[row][col - 1] != 2) {
                visited[row][col - 1] = 2;
                q.push({{row, col - 1}, time + 1});
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] != 2) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
