class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int result = 0;
        for (int i=1;i<prices.size();i++){
            if (min>prices[i]){
                min = prices[i];
            }else if (prices[i] - min > result){
                result = prices[i] - min;
            }
        }
        return result;
        
    }
};