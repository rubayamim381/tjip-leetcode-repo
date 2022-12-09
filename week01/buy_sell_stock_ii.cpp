/*
Peak Valley Approach Algorithm
TC: O(n)
MC: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& price) {
        int dayLen = price.size();
        if(dayLen==0) return 0;

        int maxProfit=0, valley=price[0], peak=price[0], left=0, right=dayLen-1;

        while(left < right)
        {
            while(left < right && price[left] >= price[left+1]) left++;
            valley = price[left];

            while(left < right && price[left] <= price[left+1]) left++;
            peak = price[left];

            maxProfit += peak-valley;

        }
        return maxProfit;
    }
};

/*
approach 2: one pass approach
tc: O(n)O(n)
mc: O(1)O(1)

*/
class Solution {
public:
    int maxProfit(vector<int>& price) {
        if(price.size() == 0) return 0;
        int maxProfit = 0;
        for(int i = 1; i < price.size() ; i++){
            if(price[i]>price[i-1])
            maxProfit += price[i] - price[i-1];
        }
        return maxProfit;
    }
};

