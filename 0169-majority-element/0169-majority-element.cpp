class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& it : nums) {
            mp[it]++;
        }
        int val = 0;
        int ans = 0;
        for (auto& m : mp) {
            if (m.second > val) {
                val = m.second;
                ans = m.first;
            }
        }
        return ans;
    }
};