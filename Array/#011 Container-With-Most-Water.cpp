class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int area = 0;
        int MaxArea = 0;
        int right = height.size() -1;
        while(left<right)
        {
            area = (right - left)*(min(height[left],height[right]));
            if(area>MaxArea)
            {
                MaxArea = area;
            }
            if(height[left]<height[right]) left++;
            else right--;
        }
        return MaxArea;    
    }
};