class Solution {
public:
    int n;
    vector<vector<int>>ans;
    void solve(vector<int>& nums,int i, vector<int>val){
        if(i==n){
            ans.push_back(val);
            return;
        }
            val.push_back(nums[i]);
            solve(nums,i+1,val);
            val.pop_back();
            solve(nums,i+1,val);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
         vector<int>val;
        solve(nums,0,val);
        return ans;
    }
};