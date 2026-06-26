class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long ans = 0;
        unordered_map<int, int> mp;
        int currsum = 0;
        mp[0] = 1;
        long long validleft = 0;
        for (auto x : nums) {
            if (x == target) {
                validleft += mp[currsum];
                currsum++;
            } else {
                currsum--;
                validleft -= mp[currsum];
            }
            mp[currsum]++;
            ans += validleft;
        }
        return ans;
    }
};
