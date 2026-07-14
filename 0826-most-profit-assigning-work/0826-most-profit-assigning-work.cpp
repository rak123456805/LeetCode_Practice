class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> ans;
        for (int i = 0; i < difficulty.size();i++) {
            ans.push_back({difficulty[i], profit[i]});
        }
        sort(ans.begin(), ans.end());
         for (int i = 1; i < ans.size(); i++) {
            ans[i].second = max(ans[i].second, ans[i - 1].second);
        }
        int res=0;
        for (int i = 0; i < worker.size(); i++) {
            int val = worker[i];
            auto it =upper_bound(ans.begin(), ans.end(), make_pair(val, INT_MAX))-ans.begin();
            if(it!=NULL){
                it--;
                res+=ans[it].second;
            }
        }
        return res;
    }
};