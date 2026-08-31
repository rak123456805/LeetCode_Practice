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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *temp=head;
        vector<int>ans;
        while(temp->next!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        ans.push_back(temp->val);
        int first=-1;
        int prev=-1;
        int minDist=INT_MAX;
        for(int i=1;i<ans.size()-1;i++){
            if((ans[i]>ans[i-1]&&ans[i]>ans[i+1])||(ans[i]<ans[i-1]&&ans[i]<ans[i+1])){
                if(first==-1){
                    first=i;
                }
                else{
                    minDist=min(minDist,i-prev);
                }
                prev=i;
            }
        }
        if(first==-1 || first==prev)return {-1,-1};
        return {minDist,prev-first};
    }
};