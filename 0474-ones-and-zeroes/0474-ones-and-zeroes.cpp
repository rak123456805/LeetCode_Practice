class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int res=0;
        array<array<int, 101>, 101> dp{};
        for(auto & s : strs){
            string a=s;
            int ones=count(a.begin(),a.end(),'1');
            int zero=count(a.begin(),a.end(),'0');
            for(int i=m;i>=zero;i--){
                for(int j=n;j>=ones;j--){
                    dp[i][j]=max(dp[i][j],1+dp[i-zero][j-ones]);
                }
            }
        }
        return dp[m][n];
    }
};