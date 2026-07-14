class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue=prices[0];
        int maxprofit=0;
        int profit=0;
        for(int i=0;i<prices.size();i++){
            if(minValue>prices[i]){
                minValue=prices[i];
            }
            profit=prices[i]-minValue;
            maxprofit=max(maxprofit,profit);
        }
        return maxprofit;
    }
};