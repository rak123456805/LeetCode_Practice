class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>p(n,1);
        int prev=1;
        for(int i=0;i<n;i++){
            p[i]=prev;
            prev*=nums[i];
        }
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            p[i]*=suffix;
            suffix*=nums[i];
        }
        return p;
    };
};