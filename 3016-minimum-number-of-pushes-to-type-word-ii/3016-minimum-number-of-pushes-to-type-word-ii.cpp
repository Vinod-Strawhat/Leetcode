class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> freq(26,0);
        vector<bool> in(26,false);
        for(int i=0;i<word.size();i++){
            if(!in[word[i]-'a']){
                
                in[(word[i]-'a')]=true;
            }
            freq[(word[i]-'a')]++;
        }
        vector<pair<char,int>> v;
        for(int i=0;i<freq.size();i++){
            if(freq[i]>0){
                v.push_back({'a'+i , freq[i]});
            }
        }
        sort(v.begin(), v.end(), [](const pair<char,int>& a, const pair<char,int>& b) {
    return a.second > b.second;
    });
        int ans=0;
        if(v.size()<=8){
            for(int i=0;i<v.size();i++){
                ans+=1*v[i].second;
            }
        }
        else{
            int count=v.size();
            int st=0;
            int place=1;
            while(count>8){
                for(int i=st;i<st+8;i++){
                    ans+=place*v[i].second;
                }
                place++;
                count-=8;
                st+=8;
            }
            for(int i=st;i<v.size();i++){
                ans+=place*v[i].second;
            }
        }
        return ans;
        
    }
};