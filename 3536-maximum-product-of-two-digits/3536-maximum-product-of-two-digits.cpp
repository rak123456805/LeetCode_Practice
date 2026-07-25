class Solution {
public:
    int maxProduct(int n) {
        string ans=to_string(n);
        sort(ans.begin(),ans.end());
        int k=ans.size();
        if(k==1)return ans[0]-'0';
        int a=ans[k-1]-'0';
        int b=ans[k-2]-'0';
        return a*b;
    }
};