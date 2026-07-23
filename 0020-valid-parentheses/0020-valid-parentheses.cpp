class Solution {
public:
    bool isValid(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                ans.push_back(s[i]);
            else if (!ans.empty() && s[i] == ')' && ans.back() == '(')
                ans.pop_back();
            else if (!ans.empty() && s[i] == '}' && ans.back() == '{')
                ans.pop_back();
            else if (!ans.empty() && s[i] == ']' && ans.back() == '[')
                ans.pop_back();
            else
                return false;
        }
        if (ans.empty())
            return true;
        return false;
    }
};