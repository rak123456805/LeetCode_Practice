class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int le=0;
        int ans=0;
        for(int ri=0;ri<nums.size();ri++){
            mp[nums[ri]]++;
            while(mp[nums[ri]]>k){
                mp[nums[le]]--;
                le++;
            }
            ans=max(ans,ri-le+1);
        }
        return ans;
    }
};