class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>>ans;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            vector<int>res;
            for(int j=0;j<n;j++){
                int r1=max(0,i-k);
                int r2=min(i+k,m-1);

                int c1=max(0,j-k);
                int c2=min(j+k,n-1);
                int val=0;
                 for(int r = r1; r <= r2; r++) {
                    for(int c = c1; c <= c2; c++) {
                        val += mat[r][c];
                    }
                }
                res.push_back(val);
            }
            ans.push_back(res);
        }
        return ans;
    }
};