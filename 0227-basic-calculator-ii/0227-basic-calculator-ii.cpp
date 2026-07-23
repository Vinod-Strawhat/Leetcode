class Solution {
public:
    int calculate(string str) {
        stack<int> s;
        stack<char> op;
        unordered_map<char,int> mp;
        mp['-']=1;
        mp['+']=1;
        mp['*']=2;
        mp['/']=2;
        int i=0;
        while(i<str.size()){
            if(isspace(str[i])){
                i++;
                continue;
            }
            if(isdigit(str[i])){
                string samp="";
                int temp=0;
                while(i<str.size() && isdigit(str[i])){
                    samp=samp+str[i];
                    i++;
                }
                temp=stoi(samp);
                s.push(temp);
            }
            else{
                while(!op.empty() && mp[str[i]]<=mp[op.top()]){
                    if(op.top()=='+'){
                        int second=s.top();
                        s.pop();
                        int first=s.top();
                        s.pop();
                        int ans=first+second;
                        s.push(ans);
                        op.pop();
                        
                        
                }
                else if(op.top()=='-'){
                    int second=s.top();
                        s.pop();
                        int first=s.top();
                        s.pop();
                        int ans=first-second;
                        s.push(ans);
                        op.pop();
                        
                }
                else if(op.top()=='*'){
                    int second=s.top();
                        s.pop();
                        int first=s.top();
                        s.pop();
                        int ans=first*second;
                        s.push(ans);
                        op.pop();
                        
                }
                else if(op.top()=='/'){
                    int second=s.top();
                    s.pop();
                    int first=s.top();
                    s.pop();
                    int ans=first/second;
                    s.push(ans);
                    op.pop();
                    
                }
                }
                
              op.push(str[i]);
              i++;}
            
        }
        while(!op.empty()){
            int second=s.top();
            s.pop();
            int first=s.top();
            s.pop();
            int an=0;
            if(op.top()=='+'){
                an=first+second;
            }
            else if(op.top()=='-'){
                an=first-second;
            }
            else if(op.top()=='*'){
                an=first*second;
            }
            else if(op.top()=='/'){
                an=first/second;
            }
            s.push(an);
            op.pop();
        }
        return s.top();
    }
};