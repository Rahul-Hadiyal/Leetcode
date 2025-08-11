class Solution {
public:
    int jump(vector<int>& nums) {
        int pas = 0, far = 0, jumps = 0;

        while (far < nums.size() - 1) {
            int door = 0;
            for (int i = pas; i <= far; i++) {
                door = max(door, i + nums[i]);
            }
            pas = far + 1;
            far = door;
            jumps++;
        }

        return jumps;        
    }
};