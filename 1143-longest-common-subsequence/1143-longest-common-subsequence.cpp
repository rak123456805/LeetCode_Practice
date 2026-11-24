class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int solve(const string &s1,const string &s2,int i,int j){
        if(i>=n || j>=m)return 0;
        int take;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return 1+solve(s1,s2,i+1,j+1);
        }
        int leave=solve(s1,s2,i+1,j);
        int leave2=solve(s1,s2,i,j+1);
        return dp[i][j]=max(leave,leave2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        n=text1.size();
        m=text2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(text1,text2,0,0);
    }
};