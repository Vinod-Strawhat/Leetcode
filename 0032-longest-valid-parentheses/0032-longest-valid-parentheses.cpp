class Solution {
public:
    int longestValidParentheses(string s) {
         stack<int> st;
         int maxi=0;
         for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]==')' && s[st.top()]=='('){
                st.pop();
                if(st.empty()){
                    maxi=max(i+1, maxi);
                }
                else{
                    maxi=max(i-st.top(),maxi);
                }
            }
            else{
            st.push(i);
            }
         }
         return maxi;
    }
};