class Solution {
public:
    int longestValidParentheses(string s) {
        int le = 0, ri = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                le++;
            else
                ri++;
            if (le == ri)
                ans = max(ans, le * 2);
            else if (ri > le) {
                le = 0;
                ri = 0;
            }
        }
        le = 0;
        ri = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(')
                le++;
            else
                ri++;
            if (le == ri)
                ans = max(ans, le * 2);
            else if (le>ri) {
                le = 0;
                ri = 0;
            }
        }
        return ans;
    }
};