class Solution {
public:
    int arraySign(vector<int>& nums) {
        auto ans=0;
        for(auto &x:nums){
            if(x==0)return 0;
            else if (x<0)ans++;
        }
        return ans%2?-1:1;
    }
};