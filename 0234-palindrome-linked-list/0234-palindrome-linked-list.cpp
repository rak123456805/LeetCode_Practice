/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* tail = head;
        vector<int>ans;
        if (head == NULL)
            return NULL;
        while (tail->next != NULL) {
            ans.push_back(tail->val);
            tail = tail->next;
        }
        ans.push_back(tail -> val);
        vector<int>rev;
        rev=ans;
        reverse(rev.begin(),rev.end());
        return rev==ans;
    }
    
};