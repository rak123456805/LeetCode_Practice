class Solution {
public:
    int minRotations(string s) {
        int ans=0;
        int val=s[0]-'0';
        int m1=val;
        int m2=10-m1;
        ans+=min(m1,m2);
        for(int i=1;i<s.size();i++){
            int a=s[i-1]-'0';
            int b=s[i]-'0';
            m1=abs(a-b);
            m2=10-m1;
            ans+=min(m1,m2);
        }
        return ans;
    }
};