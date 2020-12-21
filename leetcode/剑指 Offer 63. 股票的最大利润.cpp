class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int minPrice = prices[0];
        int ret = 0;
        for (int price : prices) {
            ret = max(ret, price - minPrice);
            minPrice = min(minPrice, price);
        }
        return ret;
    }
};