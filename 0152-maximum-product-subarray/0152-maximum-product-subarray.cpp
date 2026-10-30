class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        for(int i=0;i<nums.size();i++){
            int p=nums[i];
            ans=max(ans,p);
            for(int j=i+1;j<nums.size();j++){
                p*=nums[j];
                if(p==0)continue;
                ans=max(ans,p);
            }
        }
        return ans;
    }
};