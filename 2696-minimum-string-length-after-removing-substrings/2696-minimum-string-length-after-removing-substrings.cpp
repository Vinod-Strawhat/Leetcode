class Solution {
public:
    int minLength(string s) {
        if(s.size()==1){
            return 1;
        }
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='B'){
                if(!st.empty() &&st.top()=='A'){
                    st.pop();
                    continue;
                }
                else{
                    st.push(s[i]);
                    continue;
                }
                
            }
            
            if(s[i]=='D'){
                if(!st.empty() && st.top()=='C'){
                    st.pop();
                    continue;
                }
                else{
                    st.push(s[i]);
                    continue;
                }
            }
            st.push(s[i]);
        }
        int count=0;
        while(!st.empty()){
            count++;
            st.pop();
        }
        return count;
    }
};