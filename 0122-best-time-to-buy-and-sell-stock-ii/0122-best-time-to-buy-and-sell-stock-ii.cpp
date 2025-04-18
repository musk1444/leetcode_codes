class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int aheadnotbuy = 0;
        int aheadbuy = 0;
        
        int currnotbuy, currbuy;
        for(int i = n-1; i>= 0; i--)
        {
            currnotbuy = max((prices[i] + aheadbuy), (0 + aheadnotbuy));

            currbuy = max( (-prices[i] + aheadnotbuy), (0 + aheadbuy));

            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }

        return aheadbuy;
    }
};