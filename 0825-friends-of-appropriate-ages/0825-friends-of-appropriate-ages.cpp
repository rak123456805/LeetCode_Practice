class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        sort(ages.begin(), ages.end());
        for (int i = 0; i < ages.size(); i++) {
            int A = ages[i];
            if (A <= 14)
                continue;
            int left =
                upper_bound(ages.begin(), ages.end(), A / 2 + 7) - ages.begin();
            int right = upper_bound(ages.begin(), ages.end(), A) - ages.begin();
            ans += (right - left - 1);
        }

        return ans;
    }
};