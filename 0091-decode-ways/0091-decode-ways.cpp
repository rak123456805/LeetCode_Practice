class Solution {
public:
    unordered_map<string,int> dp;

    int solve(string &s, string curr, int i) {

        string key = to_string(i) + "#" + curr;

        if(dp.count(key))
            return dp[key];

        if(curr != ""){
            int num = stoi(curr);

            if(num < 1 || num > 26)
                return dp[key] = 0;

            if(i == s.size())
                return dp[key] = 1;
        }

        if(i >= s.size())
            return dp[key] = 0;

        int take = solve(s, curr + s[i], i + 1);

        int split = 0;

        if(curr != "")
            split = solve(s, string(1,s[i]), i + 1);

        return dp[key] = take + split;
    }

    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;

        return solve(s,"",0);
    }
};