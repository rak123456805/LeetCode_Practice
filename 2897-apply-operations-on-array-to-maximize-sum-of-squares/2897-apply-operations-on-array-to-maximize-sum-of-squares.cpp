class Solution {
public:
    int M = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> bit(32, 0);
        for (int& num : nums) {
            for (int j = 0; j < 32; j++) {
                if (num & (1 << j)) { //and operation gives whether there is an 1 in that position
                    bit[j]++;
                }
            }
        }
        long long result = 0;
        while (k--) {
            long long curr = 0;
            for (int i = 0; i < bit.size(); i++) {

                if (bit[i] > 0) {
                    bit[i]--;
                    curr = (curr | (1 << i)); // or operation adds the value
                }
            }
            result = (result + (curr * curr)) % M;
        }
        return result;
    }
};