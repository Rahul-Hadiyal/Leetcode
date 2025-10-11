class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        vector <int> pairs(n);
        for(int i = 0; i<n ; i++)
        {
            int left = 0;
            int right = m - 1;
            while(left <= right)
            {
                int mid = left + ( right - left )/2;
                if((long long)potions[mid]*spells[i] >= success)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            pairs[i] = m - left;
        }
        return pairs;
    }
};