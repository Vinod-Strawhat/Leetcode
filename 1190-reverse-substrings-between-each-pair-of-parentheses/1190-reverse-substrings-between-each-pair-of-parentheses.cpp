class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                string holder="";
                while(st.top()!='('){
                    holder+=st.top();
                    st.pop();
                }
                st.pop();
                for(int j=0;j<holder.size();j++){
                    st.push(holder[j]);
                }
            }
            else{
            st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};