
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        if(n <= 1) return 0;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(i == 0) {
                if(nums[i] > nums[i+1]) {
                    mini = min(mini, nums[i]);
                    maxi = max(maxi, nums[i]);
                }
            }
            else if(i == n-1) {
                if(nums[i] < nums[i-1]) {
                    mini = min(mini, nums[i]);
                    maxi = max(maxi, nums[i]);
                }
            }
            else {
                if(nums[i] < nums[i-1] || nums[i] > nums[i+1]) {
                    mini = min(mini, nums[i]);
                    maxi = max(maxi, nums[i]);
                }
            }
        }

        if(mini == INT_MAX) return 0;

        int s = 0, l = n-1;

        while(s < n && nums[s] <= mini) {
            s++;
        }

        while(l >= 0 && nums[l] >= maxi) {
            l--;
        }

        return l - s + 1;
    }
};
