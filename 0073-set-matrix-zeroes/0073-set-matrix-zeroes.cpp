class Solution {
public:
    int m,n;
    void solve(vector<vector<int>>& matrix,int i,int j){
        for(int k = 0; k < n; k++) {
            matrix[i][k] = 0;
        }
        for(int k = 0; k < m; k++) {
            matrix[k][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        m=matrix.size();n=matrix[0].size();
        vector<pair<int,int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    ans.push_back({i,j});
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            int k=ans[i].first;
            int j=ans[i].second;
            solve(matrix,k,j);
        }
    }
};