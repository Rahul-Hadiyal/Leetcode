class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> res;
        for(int i=0;i<nums.size();i++){
            if (nums[i]==target){
                res.push_back(i);
                break; 
            }
        }
        for (int j=nums.size()-1;j>=0;j--){
            if(nums[j]==target){
                res.push_back(j);
                break;
            }
        }
        if (res.size()==0){
            return {-1,-1};
        }else{
            return res;
        }
    }
};