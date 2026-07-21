class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<char,int>> groups;
        string as="";
        as+='1';
        for(int i=0;i<s.size();i++){
            
            as+=s[i];
        }
        as+='1';
        int count=1;
        char ch=as[0];
        for(int i=1;i<as.size();i++){
            if(as[i]==ch){
                count++;
            }
            else{
                groups.push_back({ch,count});
                ch=as[i];
                count=1;
            }
        }
            
        
        groups.push_back({ch, count});
        int totalOnes = 0;
    for(char c : s)
        if(c == '1')
            totalOnes++;
            int maxi=totalOnes;
    for(int i=1;i+1<groups.size();i++){
        if(groups[i-1].first=='0' && groups[i].first=='1' && groups[i+1].first=='0'){
            maxi=max(maxi,totalOnes+groups[i+1].second + groups[i-1].second);
        }
    }   
    return maxi;     
    }
};