class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int current_sum=0;
        for (int i=0;i<nums.size();i++){
            current_sum+=nums[i];
            maxsum = max(current_sum,maxsum);
            if (current_sum<0){
                current_sum=0;
            }
        }
        return maxsum;
        
    }
};