class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
          for(int i = 1; ; i++) {
            int val = i * k;

            if(mp.find(val) == mp.end()) {
                return val;
            }
        }
        return -1;
    }
};