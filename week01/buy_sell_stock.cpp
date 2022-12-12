//TC: O(n), MC: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy_price=prices[0], ans=0;

        for(int i=1;i<prices.size();i++)
            {
               if(buy_price>prices[i])
                   buy_price=prices[i];
              else
                  ans=max(prices[i]-buy_price, ans);
            }
        return ans;
    }
};
