class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int min1=min_element(nums.begin(),nums.end())-nums.begin();
        int max1=max_element(nums.begin(),nums.end())-nums.begin();
        if (min1 > max1)
            swap(min1, max1);

        int ans1 = max1 + 1;                    // both from front
        int ans2 = n - min1;                    // both from back
        int ans3 = (min1 + 1) + (n - max1);     // min front, max back

        return min({ans1, ans2, ans3});
    }
};