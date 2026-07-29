class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int ans=0;
      int n=nums.size();
      unordered_map<int,int>pri;
      int sum=0;
      pri[0]=1;
      for(int i=0;i<n;i++){
        sum+=nums[i];
        int rem=sum-k;
        ans+=pri[rem];
        pri[sum]++;
      }
      return ans;
    }
};