class Solution {
public:
    int digisum(int a){
        int sum=0;
        while(a>0){
            int rem=a%10;
            sum+=rem;
            a/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,digisum(nums[i]));
        }
        return mini;
    }
};