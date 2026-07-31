class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;
        int le = 0;
        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++) {

            mp[s[i]]++;

            while (mp[s[i]] > 1) {
                mp[s[le]]--;
                le++;
            }

            ans = max(ans, i - le + 1);
        }

        return ans;
    }
};