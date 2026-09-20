class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            char cnt=s[i];
            int val=(i+1)*(123-cnt);
            ans+=val;
        }
        return ans;
    }
};