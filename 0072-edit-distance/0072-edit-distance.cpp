class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int solve(string word1, string word2,int i,int j){
        if(i==n)return m-j;
        if(j==m)return n-i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j])return dp[i][j]=solve(word1,word2,i+1,j+1);
        int ins=1+solve(word1,word2,i,j+1);
        int del=1+solve(word1,word2,i+1,j);
        int rep=1+solve(word1,word2,i+1,j+1);
        return dp[i][j]=min({ins,del,rep});
    }
    int minDistance(string word1, string word2) {
       n=word1.size();
       m=word2.size();
       dp.assign(n+1,vector<int>(m+1,-1));
       return solve(word1,word2,0,0); 
    }
};