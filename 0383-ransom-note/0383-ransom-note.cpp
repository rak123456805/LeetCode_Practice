class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> r(26, 0);
        vector<int> m(26, 0);
        for (int i = 0; i < ransomNote.size(); i++) {
            int val = ransomNote[i] - 'a';
            r[val]++;
        }
        for (int i = 0; i < magazine.size(); i++) {
            int val = magazine[i] - 'a';
            m[val]++;
        }
        for (int i = 0; i < 26; i++) {
            if (m[i] < r[i])
                return false;
        }
        return true;
    }
};