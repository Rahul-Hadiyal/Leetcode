class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string &t : tokens) {
            // If token is an operator
            if (t == "+" || t == "-" || t == "*" || t == "/" || t == "^") {
                int val2 = st.top(); st.pop();
                int val1 = st.top(); st.pop();

                if (t == "+") st.push(val1 + val2);
                else if (t == "-") st.push(val1 - val2);
                else if (t == "*") st.push(val1 * val2);
                else if (t == "/") st.push(val1 / val2);  // assumes no division by zero
            } 
            else {
                // Convert string number to int
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
