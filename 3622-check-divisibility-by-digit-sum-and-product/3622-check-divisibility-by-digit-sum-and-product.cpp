class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int temp=n;
    while(temp>0){
        int rem=temp%10;
        prod*=rem;
        sum+=rem;
        temp/=10;
    }
    int total=sum+prod;
    return n%total==0;
    }
};