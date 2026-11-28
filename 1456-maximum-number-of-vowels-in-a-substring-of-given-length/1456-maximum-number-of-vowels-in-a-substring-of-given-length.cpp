class Solution {
public:
    bool solve(char v) {
        if (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        for (int i = 0; i < k; i++) {
            if (solve(s[i]))
                ans++;
        }
        int cnt = ans;
        for (int i = k; i < s.size(); i++) {
            if (solve(s[i - k]))
                cnt--;
            if (solve(s[i]))
                cnt++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};