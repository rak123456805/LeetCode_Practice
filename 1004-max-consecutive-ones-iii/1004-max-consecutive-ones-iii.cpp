class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int le=0;
        int zero=0;
        int ans=0;
        for(int ri=0;ri<nums.size();ri++){
            if(nums[ri]==0)zero++;
            if(zero>k){
                if(nums[le] == 0) zero--;
                le++;
            }
            ans=max(ans,ri-le+1);
        }
        return ans;
    }
};