class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        for(int i=l;i<=r;i++){
            int sum=0;
            for(int j=0;j<i;j++){
                sum+=nums[j];
            }
            if(sum>0) ans=min(ans,sum);
            int low=0,high=i;
            while(high<nums.size()){
                sum-=nums[low];
                sum+=nums[high];
                low++,high++;
                if(sum>0){
                    ans=min(sum,ans);
                }
            }
        }
        
        return (ans==INT_MAX)?-1:ans;
    }
};