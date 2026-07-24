class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>pair;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                pair.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int>res;
        for(auto & a : pair){
            for(auto & x : nums){
                res.insert(a ^ x);
            }
        }
        return res.size();
    }
};