class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=INT_MIN;
        unordered_map<char,int>mp;
        int le=0;
        for(int ri=0;ri<n;ri++){
            mp[s[ri]]++;
            while(mp[s[ri]]>1){
                mp[s[le]]--;
                le++;
            }
            ans=max(ans,ri-le+1);
        }
        return ans==INT_MIN?0:ans;
    }
};