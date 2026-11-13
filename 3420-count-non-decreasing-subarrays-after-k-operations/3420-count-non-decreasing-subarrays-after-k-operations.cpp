class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long op = 0;
        priority_queue<pair<int, int>> q;
        vector<vector<int>> cnt(n);
        vector<int> pos(n, n);
        stack<int> st;
        int le = 0;
        for (int ri = 0; ri < n; ri++) {
            while (!st.empty() && nums[ri] >= nums[st.top()]) {
                pos[st.top()] = ri;
                st.pop();
            }
            if (!st.empty()) {
                cnt[st.top()].push_back(ri);
            }
            st.push(ri);
            q.emplace(nums[ri], ri);
            op += max(0, q.top().first - nums[ri]);
            while (op > k) {
                for (int i : cnt[le]) {
                    op -= (long long)(nums[le] - nums[i]) *
                          (min(pos[i], ri + 1) - i);
                }
                le++;
            }
            while (!q.empty() && q.top().second < le) {
                q.pop();
            }
            ans += ri - le + 1;
        }
        return ans;
    }
};