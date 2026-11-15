class Solution {
public:
    int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int pri = 0;
        int e = 1;
        int o = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            pri += (arr[i]%M);
            if (pri % 2 != 0) {
                ans=(ans+(e%M))%M;
                o++;
            } else {
                ans =(ans+(o%M))%M;
                e++;
            }
        }
        return ans%M;
    }
};