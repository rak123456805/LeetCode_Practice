class Solution {
public:
    int n;

    bool solve(vector<int>& nums1, int val, bool ev) {
        vector<int> ans = nums1;

        if (ev) {
            for (int i = 0; i < n; i++) {
                if (ans[i] % 2 == 0) {
                    continue;
                } 
                else {
                    if (ans[i] - val >= 1 && ans[i] != val) {
                        ans[i] = ans[i] - val;
                    } 
                    else {
                        return false;
                    }
                }
            }
        } 
        else {
            for (int i = 0; i < n; i++) {
                if (ans[i] % 2 != 0) {
                    continue;
                } 
                else {
                    if (ans[i] - val >= 1 && ans[i] != val) {
                        ans[i] = ans[i] - val;
                    } 
                    else {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool uniformArray(vector<int>& nums1) {
        n = nums1.size();

        int mine = INT_MAX;
        int mino = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0) {
                mine = min(mine, nums1[i]);
            } 
            else {
                mino = min(mino, nums1[i]);
            }
        }

        // Try making everything even
        if (mino != INT_MAX) {
            if (solve(nums1, mino, true)) {
                return true;
            }
        }

        // Try making everything odd
        if (mino != INT_MAX) {
            if (solve(nums1, mino, false)) {
                return true;
            }
        }

        // Already all even
        if (mino == INT_MAX) {
            return true;
        }

        return false;
    }
};