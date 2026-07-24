class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            bool ok=true;
            if(isupper(s[i])){
                if(!st.empty() && char(s[i]+' ')==st.top()){
                    st.pop();
                    ok=false;
                }
            }
            else{
                if(!st.empty() && char(s[i]-' ')==st.top()){
                    st.pop();
                    ok=false;
                }
            }
            if(ok){
            st.push(s[i]);}
        }
        string ans="";
        while(!st.empty()){
            ans.insert(ans.begin(),st.top());
            st.pop();
        }
        return ans;
    }
};