class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();i++){
            if (nums[i]>=0){
                if (ans == nums[i]){
                    ans ++;
                }else if (nums[i]>ans){
                    return ans;
                }
            }
        }
        return ans;
        
    }
};