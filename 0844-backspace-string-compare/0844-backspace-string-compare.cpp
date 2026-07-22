class Solution {
public:
    string bc(string v){
        stack<char> s;
        for(int i=0;i<v.size();i++){
        if(v[i]=='#'){
            if(!s.empty()){
            s.pop();
            }
        }
        else{
            s.push(v[i]);
        }
        }
        string ans="";
        while(!s.empty()){
            ans.insert(ans.begin(),s.top());
            s.pop();
        }
        return ans;

    }
    bool backspaceCompare(string s, string t) {
        string a1=bc(s);
        string a2=bc(t);
        return a1==a2;
    }
};