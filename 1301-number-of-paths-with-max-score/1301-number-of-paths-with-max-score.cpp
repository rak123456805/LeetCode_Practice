class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    vector<string> board;

    vector<vector<int>> dpScore;
    vector<vector<int>> dpWays;

    pair<int,int> solve(int i, int j) {
        if (i < 0 || j < 0 || board[i][j] == 'X')
            return {-1000000000, 0};

        if (i == 0 && j == 0)
            return {0, 1};

        if (dpScore[i][j] != -1)
            return {dpScore[i][j], dpWays[i][j]};

        auto up   = solve(i - 1, j);
        auto left = solve(i, j - 1);
        auto diag = solve(i - 1, j - 1);

        int best = max({up.first, left.first, diag.first});

        if (best < 0) {
            dpScore[i][j] = -1000000000;
            dpWays[i][j] = 0;
            return {dpScore[i][j], dpWays[i][j]};
        }

        long long ways = 0;

        if (up.first == best)
            ways = (ways + up.second) % MOD;

        if (left.first == best)
            ways = (ways + left.second) % MOD;

        if (diag.first == best)
            ways = (ways + diag.second) % MOD;

        int val = 0;
        if (board[i][j] != 'S' && board[i][j] != 'E')
            val = board[i][j] - '0';

        dpScore[i][j] = best + val;
        dpWays[i][j] = ways;

        return {dpScore[i][j], dpWays[i][j]};
    }

    vector<int> pathsWithMaxScore(vector<string>& b) {
        board = b;
        n = board.size();

        dpScore.assign(n, vector<int>(n, -1));
        dpWays.assign(n, vector<int>(n, -1));

        auto ans = solve(n - 1, n - 1);

        if (ans.second == 0)
            return {0, 0};

        return {ans.first, ans.second};
    }
};