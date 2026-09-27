class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                string val;
                while (!st.empty() && st.top() != '(') {
                    val += st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop();
                }
                for (auto& c : val) {
                    st.push(c);
                }
            } else {
                st.push(s[i]);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};