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
                    dub.erase(0, 1);
                    cout << dub << " ";
                    ans += dub;
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