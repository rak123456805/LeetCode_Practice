class Solution {
public:
    int sumCounts(vector<int>& nums) {
        vector<set<int>> st;
        int n=nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                set<int> sub;
                for (int k = i; k <= j; k++)
                    sub.insert(nums[k]);
                st.push_back(sub);
            }
        }
        int ans=0;
        for(int i=0;i<st.size();i++){
            int val=st[i].size();
            cout<<val<<" ";
            ans+=(val*val);
        }
        return ans;
    }
};