class Solution {
public:
    int sumCounts(vector<int>& nums) {
        vector<set<int>> st;
        int n=nums.size();
         for (int i = 0; i < n; i++) {
            set<int> sub;

            for (int j = i; j < n; j++) {
                sub.insert(nums[j]);
                st.push_back(sub);
            }
        }
        int ans=0;
        for(int i=0;i<st.size();i++){
            int val=st[i].size();
            ans+=(val*val);
        }
        return ans;
    }
};