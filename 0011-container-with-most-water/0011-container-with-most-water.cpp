class Solution {
public:
    int maxArea(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int maxi=INT_MIN;
        int sum;
        while(left<right){
            sum=((min(nums[left],nums[right]))*(right-left));
            maxi=max(sum,maxi);
            if(nums[left]>nums[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxi;
    }
};