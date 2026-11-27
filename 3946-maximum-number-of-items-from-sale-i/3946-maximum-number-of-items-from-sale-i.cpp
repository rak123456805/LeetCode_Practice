class Solution {
public:
    vector<int> cnt, price, memo;
    int n, B;

    int solve(int i, int b, bool first) {
        if (i >= n || b <= 0) return 0;

        int &res = memo[((size_t)i * (B + 1) + b) * 2 + first];
        if (res != -1) return res;

        int best = solve(i + 1, b, true);                  // leave item i
        if (b >= price[i]) {                               // take one more copy of item i
            int gain = 1 + (first ? cnt[i] : 0);
            best = max(best, gain + solve(i, b - price[i], false));
        }
        return res = best;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        B = budget;
        cnt.assign(n, 0);
        price.assign(n, 0);

        for (int i = 0; i < n; i++) {
            price[i] = items[i][1];
            for (int j = 0; j < n; j++)
                if (i != j && items[j][0] % items[i][0] == 0)
                    cnt[i]++;
        }

        memo.assign((size_t)n * (B + 1) * 2, -1);
        return solve(0, B, true);
    }
};