class Solution {
public:
    int longestValidParentheses(string s) {
         stack<pair<int,int>> st;
         int maxi=0;
         for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i]==')' && st.top().first=='('){
                st.pop();
                if(st.empty()){
                    maxi=max(i+1, maxi);
                }
                else{
                    maxi=max(i-st.top().second,maxi);
                }
            }
            else{
            st.push({s[i],i});
            }
         }
         return maxi;
    }
};