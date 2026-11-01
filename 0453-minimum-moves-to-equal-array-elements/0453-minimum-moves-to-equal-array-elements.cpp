class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res=0;
        int val=*min_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
           res+=nums[i]-val;
        }
        return res;
    }
};