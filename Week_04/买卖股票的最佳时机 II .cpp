class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxMoney = 0 ;
        for (int i = 0 ;i< prices.size();i++){
            if (i + 1 < prices.size() && prices[i] < prices[i+1]){
                maxMoney+= prices[i+1] - prices[i];
            }
        }
        return maxMoney;
    }
};