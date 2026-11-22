
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i + 1 < n; i++) {
            if (nums[i + 1] < nums[i]) {
                ans.push_back(i);
            }
        }

        if (ans.size() == 0)
            return 0;

        int st = ans[0];
        int en = ans[ans.size() - 1] + 1;

        int mini = nums[st];
        int maxi = nums[st];

        for (int i = st; i <= en; i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        while (st > 0 && nums[st - 1] > mini) {
            st--;
        }

        while (en < n - 1 && nums[en + 1] < maxi) {
            en++;
        }

        return en - st + 1;
    }
};
