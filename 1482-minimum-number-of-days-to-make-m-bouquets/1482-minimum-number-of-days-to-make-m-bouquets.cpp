class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int left=1;
        int right=maxi;
        int mid=0;
        int ans=-1;
        while(left<=right){
            mid=left+(right-left)/2;
            int count=0;
            int days=0;
            for(int r=0;r<nums.size();r++){
               if(nums[r]<=mid){
                count++;
               }
               else{
                 
                 count=0;
               }
               if(count==k){
                days++;
                count=0;
               }
            }
            if(days>=m){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }


        }
        return ans;
    }
};