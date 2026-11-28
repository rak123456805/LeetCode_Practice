class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int le=0;
        int zero=0;
        int ans=INT_MIN;
        for(int ri=0;ri<n;ri++){
            if(nums[ri]==0)zero++;
            if(zero>k){
                if(nums[le]==0)zero--;
                le++;
            }
            ans=max(ans,ri-le+1);
        }
        return ans;
    }
};