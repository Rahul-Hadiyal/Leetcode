class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0;
        int currTank = 0;
        int start = 0;
        for (int i=0;i<gas.size();i++)
        {
            currTank = currTank + gas[i] - cost[i];
            totalTank = totalTank + gas[i] - cost[i];

            if(currTank < 0)
            {
                start = i+1;
                currTank = 0;
            }
        }
        return totalTank >= 0 ? start : -1 ; 
    }
};