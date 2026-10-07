class Solution {
public:
    int n;
    int maxlen;
    unordered_set<string> st;

    void solve(string &s, string& curr, int i, int cnt) {
        if (cnt < 0)
            return;

        if (i == n) {
            if (cnt == 0) {
                if (curr.length() > maxlen) {
                    maxlen = curr.length();
                    st.clear();
                }

                if (curr.length() == maxlen) {
                    st.insert(curr);
                }
            }
            return;
        }

        if (s[i] != ')' && s[i] != '(') {
            curr.push_back(s[i]);
            solve(s, curr, i + 1, cnt);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);

        solve(s, curr, i + 1, cnt + (s[i] == ')' ? -1 : +1));

        curr.pop_back();
        solve(s, curr, i + 1, cnt);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        maxlen = 0;
        st.clear();

        string curr = "";

        solve(s, curr, 0, 0);

        return vector<string>(st.begin(), st.end());
    }
};