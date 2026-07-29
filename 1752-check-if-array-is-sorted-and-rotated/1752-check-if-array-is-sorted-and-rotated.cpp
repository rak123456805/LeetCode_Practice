class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<nums.size();i++){
            int idx=0;
            for(int j=i;j<n;j++){
                ans[idx]=nums[j];
                idx++;
            }
            for(int j=0;j<i;j++){
                ans[idx]=nums[j];
                idx++;
            }
            bool issort=true;
            for(int i=0;i+1<n;i++){
                if(ans[i]>ans[i+1]){
                    issort=false;
                    break;
                }
            }
            if(issort)return true;
        }
        return false;
    }
};