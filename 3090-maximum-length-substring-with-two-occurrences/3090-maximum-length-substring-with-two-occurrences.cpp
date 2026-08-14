class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int ans = 0;
        int le = 0;
        unordered_map<int, int> mp;
        for (int ri = 0; ri < s.size(); ri++) {
            mp[s[ri]]++;
            while (mp[s[ri]] > 2) {
                mp[s[le]]--;
                le++;
            }
            ans = max(ans, ri - le + 1);
        }
        return ans;
    }
};
