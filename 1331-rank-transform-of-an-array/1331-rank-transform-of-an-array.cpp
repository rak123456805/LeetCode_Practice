class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> rank = arr;
        sort(rank.begin(), rank.end());

        rank.erase(unique(rank.begin(), rank.end()), rank.end());

        vector<int> ans;

        for(int x : arr) {
            int ind = lower_bound(rank.begin(), rank.end(), x) - rank.begin();
            ans.push_back(ind + 1);
        }

        return ans;
    }
};