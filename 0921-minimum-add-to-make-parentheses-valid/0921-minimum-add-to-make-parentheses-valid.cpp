class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()){
            if(s[i]==')' && st.top()=='('){
                st.pop();
            }
            else if(s[i]==']' && st.top()=='['){
                st.pop();
            }
            else if(s[i]=='}' && st.top()=='{'){
                st.pop();
            }
            else{
            st.push(s[i]);
            }}
            else{
                st.push(s[i]);
            }
        }
        if(st.empty()){
            return 0;
        }
        int count=0;
        while(!st.empty()){
            count++;
            st.pop();
        }
        return count;
    }
};