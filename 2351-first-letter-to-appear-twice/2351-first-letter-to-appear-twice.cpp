class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> mp;
        char ans;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]>0){
                ans=s[i];
                break;
            }
            mp[s[i]]++;
        }
        return ans;
    }
};