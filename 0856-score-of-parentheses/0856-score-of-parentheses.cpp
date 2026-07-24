class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int current = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(current);
                current = 0;
            } else {
                int previous = st.top();
                st.pop();

                if (current == 0)
                    current = previous + 1;
                else
                    current = previous + 2 * current;
            }
        }

        return current;
    }
};