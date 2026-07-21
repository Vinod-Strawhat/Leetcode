class Solution {
public:
    int smallestEvenMultiple(int n) {
        int ans=2*n;
        while((ans/2)%2==0 && ans/2 >=n){
            ans=ans/2;
        }
        return ans;
    }
};