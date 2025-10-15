class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int curr = 0;
        int pre = 0;
        int mx = 0;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++)
        {
            curr++;
            if(i == n-1 || nums[i] >= nums[i+1])
            {
                mx = max(mx,max(curr/2,min(pre,curr)));
                pre = curr;
                curr = 0;
            }
        }
        return mx>=k;
    }
};