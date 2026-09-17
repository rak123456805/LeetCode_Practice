class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> ans(n, INT_MAX);
        int sum = 0, s = 0;
        int best = INT_MAX, curr = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            while (sum > target)
                sum -= arr[s++];
            if (sum == target) {
                if (s > 0 && ans[s - 1] != INT_MAX) {
                    best = min(best, ans[s - 1] + i - s + 1);
                }
                curr = min(curr, i - s + 1);
            }
            ans[i] = curr;
        }
        return best == INT_MAX ? -1 : best;
    }
};