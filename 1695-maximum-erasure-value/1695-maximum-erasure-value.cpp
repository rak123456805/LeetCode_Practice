class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0;
        int ans = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        for (int right = 0; right < nums.size(); right++) {
            while (mp.find(nums[right]) != mp.end()) {
                mp.erase(nums[left]);
                cnt -= nums[left];
                left++;
            }
            cnt += nums[right];
            mp[nums[right]]++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};