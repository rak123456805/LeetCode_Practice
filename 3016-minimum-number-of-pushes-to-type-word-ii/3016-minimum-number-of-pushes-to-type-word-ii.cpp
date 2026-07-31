class Solution {
public:
    int minimumPushes(string word) {
        vector<int> feq(26, 0);

        for (char c : word) {
            feq[c - 'a']++;
        }

        sort(feq.rbegin(), feq.rend());

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (feq[i] == 0)
                break;
            ans += feq[i] * (i / 8 + 1);
        }

        return ans;
    }
};