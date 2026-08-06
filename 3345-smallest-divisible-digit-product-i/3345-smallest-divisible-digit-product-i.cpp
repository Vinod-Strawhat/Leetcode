class Solution {
public:
    int digits(int dig){
        int prod=1;
        while(dig>0){
            int rem=dig%10;
            prod*=rem;
            dig=dig/10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int i=n;
        while(i<=100){
            if(digits(i)%t==0){
                return i;
            }
            i++;
        }
        return -1;
    }
};