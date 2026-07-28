class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1){
            return s;
        }
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        string ans="";
        string mid="";
        bool ok=false;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                if(freq[i]%2==0){
                    ans += string(freq[i] / 2, 'a' + i); 
                }
                else{
                    ok=true;
                    if(freq[i]==1){
                    mid = string(1, 'a' + i);
                    }
                    else{
                    ans += string(freq[i] / 2, 'a' + i);
                    mid = string(1, 'a' + i);
                    }
                }
            }
        }
        string rev=ans;
        reverse(ans.begin(),ans.end());
        string final="";
        if(ok){
     final=rev+ mid +ans;
        }
        else{
            final=rev+ans;
        }
        return final;
    }
};