class Solution {
public:
    int n;
    bool ispal(string s, int st, int en) {
        while (st < en) {
            if (s[st] != s[en])
                return false;
            st++, en--;
        }
        return true;
    }
    void solve(string s, int idx, vector<string> curr,
               vector<vector<string>>& ans) {
        if (idx == n) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (ispal(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<vector<string>> ans;
        vector<string> curr;
        solve(s, 0, curr, ans);
        return ans;
    }
};