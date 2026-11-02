class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=nums[nums.size()/2];
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=abs(ans-nums[i]);
        }
        return res;
    }
};