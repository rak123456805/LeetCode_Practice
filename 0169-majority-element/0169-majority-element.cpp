class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto &e:nums){
            mp[e]++;
            if(mp[e]>(n/2))return e;
         
        }
        return -1;
    }
};