class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,1);
        int prefix = 1;
        for(int i = 0 ;i<n;i++)
        {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        int sufix = 1;
        for(int j = n-1 ; j>=0 ; j--)
        {
            answer[j] *= sufix;
            sufix *= nums[j];
        }
        return answer;

    }
};