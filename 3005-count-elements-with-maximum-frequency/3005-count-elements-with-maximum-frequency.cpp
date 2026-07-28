class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int cnt=0;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto &it : mp){
            if(it.second>mx){
                cnt=it.second;
                mx=it.second;
            }
            else if(it.second==mx){
                cnt+=it.second;
            }
        }
        return cnt;
    }
};