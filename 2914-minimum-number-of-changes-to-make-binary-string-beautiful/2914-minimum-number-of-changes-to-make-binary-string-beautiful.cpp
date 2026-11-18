class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        int x=s[0]-'0';
        for(int i=0;i<s.size();i+=2){
           if(s[i]-'0'!=s[i+1]-'0')ans++;
        }
        return ans;
    }
};