class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minvalue=prices[0];
        int maxvalue=0;
        for(auto &it : prices){
            minvalue=min(minvalue,it);
            int profit=it-minvalue;
            maxvalue=max(profit,maxvalue);
        }
        return maxvalue;
    }
};