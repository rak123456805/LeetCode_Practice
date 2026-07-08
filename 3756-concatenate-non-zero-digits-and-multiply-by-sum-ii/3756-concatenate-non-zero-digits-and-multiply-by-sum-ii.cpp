class Solution {
public:
    static const long long M = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pos;
        vector<long long> digit;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int N = pos.size();

        vector<long long> pow10(N + 1, 1);
        for (int i = 1; i <= N; i++) {
            pow10[i] = (pow10[i - 1] * 10) % M;
        }

        vector<long long> prefNum(N + 1, 0);
        for (int i = 0; i < N; i++) {
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % M;
        }

        vector<long long> prefSum(N + 1, 0);
        for (int i = 0; i < N; i++) {
            prefSum[i + 1] = prefSum[i] + digit[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x =
                (prefNum[R + 1] -
                 prefNum[L] * pow10[len] % M +
                 M) % M;

            long long sum =
                prefSum[R + 1] - prefSum[L];

            ans.push_back((int)((x * (sum % M)) % M));
        }

        return ans;
    }
};