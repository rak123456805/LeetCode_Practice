class Solution {
public:
    int n;
    vector<int>dp;
    bool ispal(const string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    int solve(const string &s,int i){
        if(i==n)return 0;
        int ans=1e9;
        if(dp[i]!=-1)return dp[i];
        for(int k=i;k<n;k++){
            if(ispal(s,i,k)){
                int p=1+solve(s,k+1);
                ans=min(ans,p);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        n=s.size();
        dp.assign(n+1,-1);
        if(s.size()==1)return 0;
        return solve(s,0)-1;
    }
};