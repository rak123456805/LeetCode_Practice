class Solution {
public:
    int reverseBits(int n) {
        vector<int>cnt(32,0);
        for(int i=0;i<32;i++){
            if(n & 1<<i)cnt[i]++;
        }
        int ans=0;
        reverse(cnt.begin(),cnt.end());
        for(int i=0;i<32;i++){
            if(cnt[i]==1){
                ans=ans|(1<<i);
            }
        }
        return ans;
    }
};