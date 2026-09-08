class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int j = i;
            unordered_map<char, int> mp;

            while (j < n) {
                if (mp[s[j]] > 0) {
                    break;
                }

                mp[s[j]]++;
                ans = max(ans, (int)mp.size());

                j++;
            }
        }

        return ans;
    }
};