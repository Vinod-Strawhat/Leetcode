class Solution {
public:
    int calculate(string str) {
        stack<long long> s;
        stack<char> op;
        int i=0;
        unordered_map<char,int> mp;
        mp['+']=2;
        mp['-']=1;
        while(i<str.size()){
            if(isspace(str[i])){
                i++;
                continue;
            }
            if(i<str.size() &&isdigit(str[i])){
                string samp="";
                long long temp=0;
                while(isdigit(str[i])){
                    samp+=str[i];
                    i++;
                }
                temp=stoll(samp);
                s.push(temp);
                
            }
            else if(str[i]=='(' || str[i]==')'){
                if(str[i]=='('){
                    op.push(str[i]);
                    i++;
                }
                else{
                    while(op.top()!='('){
                        long long second=s.top();
                        s.pop();
                        long long first=s.top();
                        s.pop();
                        if(op.top()=='+'){
                            long long sum=first+second;
                            s.push(sum);
                            op.pop();
                        }
                        else if(op.top()=='-'){
                            long long diff=first-second;
                            s.push(diff);
                            op.pop();
                        }
                    }
                    i++;
                    op.pop();
                }
            }
            else if(str[i]=='+' || str[i]=='-'){
                int j=i-1;
                while(j>=0 && isspace(str[j])){
                    j--;
                }
                bool unary=(j<0 || str[j]=='(' || str[j]=='+' || str[j]=='-');
                if(unary){
                    s.push(0);
                }
                while(!op.empty()  && op.top()!='(' && (mp[op.top()]<=mp[str[i]])){
                    long long second=s.top();
                    s.pop();
                    long long first=s.top();
                    s.pop();
                    if(op.top()=='+'){
                    long long sum=first+second;
                    s.push(sum);
                    op.pop();
                }
                else if(op.top()=='-'){
                    long long diff=first-second;
                    s.push(diff);
                    op.pop();
            }
            }
            op.push(str[i]);
            i++;
            }
        }
        while(!op.empty()){
            long long second=s.top();
            s.pop();
            long long first=s.top();
            s.pop();
            if(op.top()=='+'){
            long long sum=first+second;
            s.push(sum);
            op.pop();
           }
           else if(op.top()=='-'){
            long long diff=first-second;
            s.push(diff);
            op.pop();
            }
        }
        return (int)s.top();
    }
};