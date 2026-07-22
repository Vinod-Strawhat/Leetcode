class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> s;
        int ans=0;
        for(int i=0;i<t.size();i++){
            if(t[i]=="+" || t[i]=="-" || t[i]=="*" || t[i]=="/"){
                
                if(t[i][0]=='+'){
                    int second=s.top();
                    s.pop();
                    int first=s.top();
                    s.pop();
                    ans=first+second;
                    s.push(ans);
                }
                else if(t[i][0]=='-'){
                    int second=s.top();
                    s.pop();
                    int first=s.top();
                    s.pop();
                    ans=first-second;
                    s.push(ans);
                }
                else if(t[i][0]=='*'){
                    int second=s.top();
                    s.pop();
                    int first=s.top();
                    s.pop();
                    ans=first*second;
                    s.push(ans);
                }
                else if(t[i][0]=='/'){
                    int second=s.top();
                    s.pop();
                    int first=s.top();
                    s.pop();
                    ans=first/second;
                    s.push(ans);
                }
            }
            else{
                s.push(stoi(t[i]));
            }
            
            
        }
        return s.top();
    }
};