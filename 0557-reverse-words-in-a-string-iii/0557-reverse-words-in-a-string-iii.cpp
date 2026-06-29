class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string temp="";
            for (int j = i; j < n; j++) {
                if (j == n - 1)
                    temp += s[j];
                if (s[j] == ' '||j==n-1) {
                    reverse(temp.begin(), temp.end());
                    ans += temp + " ";
                    i=j;
                    break;
                }
                else{
                    temp+=s[j];
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};