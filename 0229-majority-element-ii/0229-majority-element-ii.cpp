class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto &e:nums){
            mp[e]++;
        }
        int n=nums.size()/3;
        for(auto &m:mp){
            if(m.second>n){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};