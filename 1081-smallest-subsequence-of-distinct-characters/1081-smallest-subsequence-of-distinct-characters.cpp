class Solution {
public:
    string smallestSubsequence(string s) {
         stack<char> st;
        vector<int> freq(26, 0);
        vector<bool> instack(26, false);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (char ch : s) {
            
            freq[ch - 'a']--;
            
            if (instack[ch - 'a'])
                continue;

            
            while (!st.empty() &&
                   st.top() > ch &&
                   freq[st.top() - 'a'] > 0) {
                instack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            instack[ch - 'a'] = true;
        }

        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};