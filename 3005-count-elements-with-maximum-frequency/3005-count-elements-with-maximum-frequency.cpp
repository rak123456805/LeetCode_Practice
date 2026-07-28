class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int cnt=0;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto &it:mp){
            cnt=max(cnt,it.second);
        }
        int ans=0;
        for(auto &it : mp){
            if(cnt==it.second){
                ans+=it.second;
            }
        }
        return ans;
    }
};