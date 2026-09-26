class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> know;
        for(int i=0;i<knowledge.size();i++){
            know[knowledge[i][0]]=knowledge[i][1];
        }
        string ans="";
        string store="";
        int n=s.size();
        int i=0;
        while(i<n){
            if(s[i]=='('){
                i++;
                while(s[i]!=')'){
                    store+=s[i];
                    i++;
                }
                i++;
               if(know.find(store)!=know.end()){
                 ans+=know[store];
                 store="";
               }
               else{
                ans+='?';
                store="";
               }
                
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};