class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k){
            return "0";
        }
        stack<char> s;
        for(int i=0;i<num.size();i++){
            while(!s.empty() &&  k>0 && num[i]<s.top()){
                s.pop();
                k--;
            }
            s.push(num[i]);
            
        }
        while(!s.empty() && k>0){
            s.pop();
            k--;
        }
        string ans="";
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        int i=0;
        while(ans[i]=='0'){
            i++;
        }
        if(i == ans.size())
             return "0";

        return ans.substr(i);
    }
};