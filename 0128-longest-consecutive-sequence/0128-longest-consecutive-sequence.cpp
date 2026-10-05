class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        if(nums.size()==0)return 0;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int ans=1;
        int cnt=1;
        vector<int> v(st.begin(), st.end());
        for(int i=1;i<v.size();i++){
            if(v[i]==(v[i-1]+1)){
                cnt++;
            }else{
                cnt=1;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};