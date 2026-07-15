class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd=0;
        int sumeven=0;
        for(int i=1;i<=n*2;i++){
            if(i%2==0){
                sumeven+=i;
            }
            else{
                sumodd+=i;
            }
        }
        int ans=gcd(sumodd,sumeven);
        return ans;
    }
};