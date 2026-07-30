class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        int place=1;
        if(word.size()<=8){
            return word.size();
        }
        
        else{
            int count=word.size();
            while(count>8){
                ans+=place*8;
                count-=8;
                place++;
            }
            ans+=place*count;
        }
        return ans;
    }
};