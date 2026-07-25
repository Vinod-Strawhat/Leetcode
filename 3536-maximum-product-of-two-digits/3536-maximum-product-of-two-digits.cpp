class Solution {
public:
    int maxProduct(int n) {
        int lar=0;
        int seclar=0;
        if(n<10){
            return n;
        }
        while(n>0){
            int rem=n%10;
            if(rem>lar){
                seclar=lar;
                lar=rem;
                
            }
            else if(rem>seclar){
                seclar=rem;
            }
            n=n/10;
        }
        return lar*seclar;
    }
};