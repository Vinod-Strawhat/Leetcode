class Solution {
public:
    int reverse(int x) {
        if(x>=INT_MAX || x<=INT_MIN){
            return  0;
        }
        long long rev=0;
        bool ok=false;
        if(x<0){
            ok=true;
        }
        long long temp=abs(x);
        while(temp>0){
            long long  rem=temp%10;
            rev=rev*10 + rem;
            temp=temp/10;
        }
        if(rev>INT_MAX || rev<INT_MIN){
            return  0;
        }
        if(ok){
            return -rev;
        }
        return rev;
    }
};