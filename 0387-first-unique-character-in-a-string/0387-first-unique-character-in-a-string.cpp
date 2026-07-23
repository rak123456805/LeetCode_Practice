class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            char A=s[i];
            mp[A]++;
        }
        int ans=INT_MAX;
        for(int i=0;i<s.size();i++){
            char A=s[i];
            if(mp[A]==1){
                ans=min(ans,i);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};