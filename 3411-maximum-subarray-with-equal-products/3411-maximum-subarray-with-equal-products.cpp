class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int prod=1,gcdv=nums[i],lcmv=nums[i],maxlcm=100000000;
            for(int j=i;j<n;j++){
                prod*=(long long)nums[j];
                if(prod>maxlcm)break;
                gcdv=gcd(gcdv,(long long)nums[j]);
                lcmv=lcm(lcmv,(long long)nums[j]);
                if(prod==gcdv*lcmv){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};