class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        nums.assign(st.begin(),st.end());
        return st.size();
    }
};