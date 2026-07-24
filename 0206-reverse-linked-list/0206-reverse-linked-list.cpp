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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode* tail = head;
        vector<int> ans;
        while (tail->next != NULL) {
            ans.push_back(tail->val);
            tail = tail->next;
        }
        ans.push_back(tail->val);
        reverse(ans.begin(), ans.end());
        ListNode dummy(0);
        ListNode* value=&dummy;
        for(auto &x : ans){
            value->next=new ListNode(x);
            value=value->next;

        }
        return dummy.next;
    }
};