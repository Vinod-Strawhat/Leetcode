class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]==')'){
                if(!st.empty() && s[i]==')' && s[st.top()]=='('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
            
        }
        string ans="";
        for(int i=s.size()-1 ;i>=0 ;i--){
            if(!st.empty() && i==st.top()){
                st.pop();
            }
            else{
                ans+=s[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};