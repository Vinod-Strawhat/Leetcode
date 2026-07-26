class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        int maxi=1;
        int mini=1;
        if(nums.size()>=3){
            maxi=nums[n]*nums[n-1]*nums[n-2];
            mini=nums[0]*nums[1]*nums[n];
        }
        return max(maxi,mini);
    }
};