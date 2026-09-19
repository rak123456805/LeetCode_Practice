class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int le=0;
        unordered_map<char,int>mp;
        for(int ri=0;ri<s.size();ri++){
            mp[s[ri]]++;
            while(mp[s[ri]]>1){
                mp[s[le]]--;
                le++;
            }
            ans=max(ans,ri-le+1);
        }
        return ans;
    }
};