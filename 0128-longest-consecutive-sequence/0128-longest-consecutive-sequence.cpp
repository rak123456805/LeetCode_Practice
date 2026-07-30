class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& it : nums) {
            mp[it]++;
        }
        int sum = 0;
        for (auto& it : mp) {
            if (mp.find(it.first - 1) == mp.end()) {
                int cnt = 1;
                int x = it.first;
                while (mp.find(x + 1) != mp.end()) {
                    x = x + 1;
                    cnt++;
                }
                sum = max(cnt, sum);
            }
        }
        return sum;
    }
};