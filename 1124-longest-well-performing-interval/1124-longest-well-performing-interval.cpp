class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        if (n == 0)
            return 0;
        vector<int> pri(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pri[i + 1] = pri[i] + (hours[i] > 8 ? 1 : -1);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (pri[j] - pri[i] > 0) {
                    res = max(res, j - i);
                }
            }
        }
        return res;
    }
};