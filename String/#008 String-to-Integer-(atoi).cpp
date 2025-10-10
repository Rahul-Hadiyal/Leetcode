class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int i = 0;
        int sign = 1;

        // Skip leading spaces
        while (i < s.size() && s[i] == ' ')
            i++;

        // Handle sign for only one
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // If next character is another sign 
        if (i < s.size() && (s[i] == '-' || s[i] == '+'))
            return 0;

        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';
            // Owerflow conditions
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7))
                return (sign == 1) ? INT_MAX : INT_MIN;
            // number formation
            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};