class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int m=*max_element(nums.begin(),nums.begin()+i);
            int l=*min_element(nums.begin()+i,nums.end());
            int ans=m-l;
            if(ans<=k)return i;
        }
        return -1;
    }
};