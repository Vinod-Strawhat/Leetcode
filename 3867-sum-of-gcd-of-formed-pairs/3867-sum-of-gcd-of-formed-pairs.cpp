class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefix(nums.size());
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            prefix[i]=gcd(maxi,nums[i]);
        }
        sort(prefix.begin(),prefix.end());
        long long sum=0;
        int left=0;
        int right=prefix.size()-1;
        while(left<right){
            sum+=gcd(prefix[left],prefix[right]);
            left++;
            right--;
        }
        return sum;

    }
};