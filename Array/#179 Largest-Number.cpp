class Solution {
public:
    static bool compare(string a,string b)
    {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> strnum;
        for(int i = 0 ; i<nums.size(); i++)
        {
            strnum.push_back(to_string(nums[i]));
        }
        sort(strnum.begin(),strnum.end(),compare);
        if (strnum[0] == "0")
            return "0";
        string result;
        for(int i = 0;i<strnum.size();i++)
        {
            result += strnum[i];
        }
        return result;
    }
};