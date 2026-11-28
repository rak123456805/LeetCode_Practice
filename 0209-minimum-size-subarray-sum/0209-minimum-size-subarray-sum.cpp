class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        int le=0;
        int sum=0;
        for(int ri=0;ri<n;ri++){
            sum+=nums[ri];
            while(sum>=target){
                ans=min(ans,ri-le+1);
                sum-=nums[le];
                le++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};