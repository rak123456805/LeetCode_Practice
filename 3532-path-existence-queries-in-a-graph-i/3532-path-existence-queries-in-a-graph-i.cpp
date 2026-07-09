class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>cnt(n,0);
        cnt[0]=0;
        int id=0;
        for(int i=1;i<n;i++){
            if(abs(nums[i]-nums[i-1])>maxDiff){
                id++;
            }
            cnt[i]=id;
        }
        for(auto &q : queries){
            int u=q[0];
            int v=q[1];
            ans.push_back(cnt[u]==cnt[v]);
        }
        return ans;
    }
};