class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int le=0;
        unordered_map<char,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp[s[i]]>1){
                mp[s[le]]--;
                le++;
            }
            ans=max(ans,i-le+1);
        }
        return ans;
    }
};