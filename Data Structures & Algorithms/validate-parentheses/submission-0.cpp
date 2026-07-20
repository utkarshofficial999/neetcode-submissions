class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char c : s) {

            // Opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {

                // No opening bracket to match
                if (st.empty())
                    return false;

                // Check matching pair
                if ((c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '['))
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};