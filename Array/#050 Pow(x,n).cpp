class Solution {
public:
    double myPow(double x, int n) {
    double result = 1;
    long long exp = n; 
    
    if (exp < 0) {
        x = 1 / x;
        exp = -exp;
    }

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result* x;
        }
        x *= x;
        exp /= 2;
    }

    return result;
    }
};