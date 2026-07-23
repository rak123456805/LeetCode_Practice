class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            char A = s[i];
            mp[A]++;
        }

        for (int i = 0; i < s.size(); i++) {
            char A = s[i];
            if (mp[A] == 1) {
                return i;
            }
        }
        return -1;
    }
};