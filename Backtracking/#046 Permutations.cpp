class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> present(nums.size(),false);
        backtrack(nums,present,result,curr);
        return result;
        
    }
private:
    void backtrack(vector <int>& nums,vector<bool>& present,vector<vector<int>>& result,vector<int>& curr)
    {
        if (curr.size() == nums.size()){
            result.push_back(curr);
            return ;
        }
        for (int i=0 ; i<nums.size() ; i++)
        {
            if (present[i]) continue;

            curr.push_back(nums[i]);
            present[i] = true;
            backtrack(nums,present,result,curr);
            curr.pop_back();
            present[i] = false;

        }

    }
};
