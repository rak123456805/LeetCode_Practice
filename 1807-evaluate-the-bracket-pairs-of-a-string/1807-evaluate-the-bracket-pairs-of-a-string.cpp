class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& word : knowledge) {
            mp[word[0]] = word[1];
        }
        string val = "";
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                j = i;
                i++;
                val.clear();
                while (i < s.size() && s[i] != ')') {
                    val += s[i];
                    i++;
                }
                string replacement;

                if (mp.find(val) != mp.end()) {
                    replacement = mp[val];
                } else {
                    replacement = "?";
                }
                s.replace(j, i - j + 1, replacement);
                i = j + replacement.size() - 1;
            }
        }
        return s;
    }
};