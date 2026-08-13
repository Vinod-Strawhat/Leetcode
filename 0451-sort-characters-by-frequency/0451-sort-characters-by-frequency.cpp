class Solution {
public:
    string frequencySort(string s) {
        map<int,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<int,int>> v(mp.begin(),mp.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        string ans="";
        for(int i=0;i<mp.size();i++){
            ans+=string(v[i].second,v[i].first);
        }
        return ans;
    }
};