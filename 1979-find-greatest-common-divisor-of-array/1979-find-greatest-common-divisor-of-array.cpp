class Solution {
public:
    int findGCD(vector<int>& nums) {
        int m=*min_element(nums.begin(),nums.end());
        int n=*max_element(nums.begin(),nums.end());
        return gcd(m,n);
    }
};