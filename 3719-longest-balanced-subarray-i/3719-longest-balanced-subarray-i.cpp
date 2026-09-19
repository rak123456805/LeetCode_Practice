#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            set<int> even;
            set<int> odd;
            int cnt = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] % 2 == 0) {
                    even.insert(nums[j]);
                    cnt++;
                } else {
                    odd.insert(nums[j]);
                    cnt++;
                }
                if (odd.size() == even.size()) {
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};