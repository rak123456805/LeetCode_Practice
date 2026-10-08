class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int op = 0;
        string dub = "";
        for (auto& c : s) {
            if (c == '(') {
                op++;
                dub += c;
            } else {
                op--;
                if (op == 0) {
                    ans.append(dub.begin() + 1, dub.end());
                    dub = "";
                    op = 0;
                } else {
                    dub += c;
                }
            }
        }
        return ans;
    }
};