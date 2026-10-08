class Solution {
public:
    int maxProduct(vector<int>& nums) {
            int ans=INT_MIN;
            for(int i=0;i<nums.size();i++){
                int sum=nums[i];
                 ans = max(ans, sum);
                for(int j=i+1;j<nums.size();j++){
                    sum*=nums[j];
                    ans=max(ans,sum);
                }
               
            }
            return ans;
    }
};