class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int mid = -1;
        while (left<=right){
            mid = left + (right - left)/2;
            long long sqr = static_cast<long long>(mid)*mid;

            if (sqr>x) right = mid - 1;
            else if (sqr<x) left = mid + 1;
            else return mid;

        }
        return static_cast<int>(std::round(right));

    }
};