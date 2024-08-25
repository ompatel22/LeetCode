class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int min=prices[0];
        for(int ele: prices){
            if(ele < min){
                min=ele;
            }
            if(ele-min > profit){
                profit=ele-min;
            }
        }
        return profit;
    }
};