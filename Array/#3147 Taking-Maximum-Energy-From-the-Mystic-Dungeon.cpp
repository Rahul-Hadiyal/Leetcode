class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int maxSum = INT_MIN;
        int n = energy.size();
        for(int i = n - 1; i>=0 ; i--)
        {
            if(i+k < n)
            {
                energy[i] += energy[i+k];
            }
            maxSum = max(maxSum , energy[i]);
        }
        return maxSum;
    }
};