class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pri(n,0);
        vector<int>suff(n,INT_MAX);
        pri[0]=nums[0];
        for(int i=1;i<n;i++){
            pri[i]=max(nums[i],pri[i-1]);
        }
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=min(suff[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            int ans=pri[i]-suff[i];
            if(ans<=k)return i;
        }
        return -1;
    }
};