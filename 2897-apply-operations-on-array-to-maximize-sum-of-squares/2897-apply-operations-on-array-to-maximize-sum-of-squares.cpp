class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int M=1e9+7;
        vector<int>bit(32,0);
        for(int &num : nums){
            for(int i=0;i<32;i++){
                if(num & (1<<i)){
                    bit[i]++;
                }
            }
        }
        long long result=0;
        while(k--){
            long long curr=0;
            for(int i=0;i<bit.size();i++){
                if(bit[i]>0){
                    bit[i]--;
                    curr=(curr|(1<<i));
                }
            }
            result=(result+(curr*curr))%M;
        }
        return result;
    }
};