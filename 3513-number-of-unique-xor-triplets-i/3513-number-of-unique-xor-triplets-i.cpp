class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return n;
        auto ans=pow(2,(floor(log2(n))+1));
        return ans;
    }
};