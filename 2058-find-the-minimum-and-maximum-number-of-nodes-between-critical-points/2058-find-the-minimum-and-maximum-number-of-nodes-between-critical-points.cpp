class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;

        ListNode* temp = head;

        while (temp != nullptr) {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        if (ans.size() <= 2)
            return {-1, -1};

        int first = -1;
        int prev = -1;
        int minDist = INT_MAX;

        for (int i = 1; i < ans.size() - 1; i++) {
            if ((ans[i] > ans[i - 1] && ans[i] > ans[i + 1]) ||
                (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])) {

                if (first == -1) {
                    first = i;
                } else {
                    minDist = min(minDist, i - prev);
                }

                prev = i;
            }
        }

        if (first == -1 || first == prev)
            return {-1, -1};

        return {minDist, prev - first};
    }
};