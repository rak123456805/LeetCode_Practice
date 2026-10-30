class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<vector<int>>& matrix) {
        for (int i = 0; i < ans.size(); i++) {
            int k = ans[i][0];
            int j = ans[i][1];
            for (int l = 0; l < matrix[0].size(); l++) {
                matrix[k][l] = 0;
            }
            for (int l = 0; l < matrix.size(); l++) {
                matrix[l][j] = 0;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    ans.push_back({i, j});
                }
            }
        }
        solve(ans, matrix);
    }
};