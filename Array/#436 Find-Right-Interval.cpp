class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector <vector<int>> start;
        vector<int> result(n);
        for(int i = 0 ; i<n ; i++)
        {
            start.push_back({intervals[i][0],i});
        }
        sort(start.begin(),start.end());
        for(int i = 0 ; i<n; i++)
        {
            int end = intervals[i][1];
            int left = 0;
            int right = n - 1;
            int idx = -1;
            while(left <= right)
            {
                int mid = left + (right - left)/2;
                if(start[mid][0] >= end)
                {
                    idx = start[mid][1];
                    right = mid - 1;
                }
                else left = mid + 1;
            }
            result[i] = idx;
        }
        return result;
    }
};