class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<long long> dp;
    vector<bool> online;
    long long k;
    int n;
    long long limit;

    const long long INF = 1e18;

    long long dfs(int u) {

        if (u == n - 1)
            return 0;

        if (dp[u] != -1)
            return dp[u];

        long long ans = INF;

        for (auto &[v, cost] : adj[u]) {

            if (cost < limit)
                continue;

            if (v != n - 1 && !online[v])
                continue;

            ans = min(ans, cost + dfs(v));
        }

        return dp[u] = ans;
    }

    bool check(long long mid) {

        limit = mid;
        dp.assign(n, -1);

        return dfs(0) <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online_,
                         long long k_) {

        online = online_;
        k = k_;
        n = online.size();

        adj.assign(n, {});

        long long mx = 0;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            adj[u].push_back({v, cost});
            mx = max(mx, (long long)cost);
        }

        long long lo = 0, hi = mx;
        long long ans = -1;

        while (lo <= hi) {

            long long mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return (int)ans;
    }
};