class Solution {
public:
    typedef long long ll;
    ll M = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<ll> pref(n, 0);
        vector<ll> sum(n, 0);
        vector<int> cnt(n, 0);
        vector<ll> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % M;
        }

        int d = s[0] - '0';

        cnt[0] = (d != 0);
        pref[0] = d;
        sum[0] = d;

        for (int i = 1; i < n; i++) {
            d = s[i] - '0';

            cnt[i] = cnt[i - 1] + (d != 0);

            if (d != 0) {
                pref[i] = (pref[i - 1] * 10 + d) % M;
            } else {
                pref[i] = pref[i - 1];
            }

            sum[i] = sum[i - 1] + d;
        }

        vector<int> res;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            ll val= sum[r] - (l == 0 ? 0 : sum[l - 1]);

            int k = cnt[r] - (l == 0 ? 0 : cnt[l - 1]);

            ll x;

            if (l == 0) {
                x = pref[r];
            } else {
                x = (pref[r] - pref[l - 1] * pow10[k] % M + M) % M;
            }

            res.push_back((x * val) % M);
        }

        return res;
    }
};