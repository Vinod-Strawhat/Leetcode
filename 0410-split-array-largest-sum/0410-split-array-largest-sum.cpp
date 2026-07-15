class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        int maxi= 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,nums[i]);
        }
        int left=maxi;
        int right=sum;
        int mid=0;
        int ans=-1;
        while(left<=right){
            mid= left+(right-left)/2;
            int count=1;
            int total=0;
            for(int i =0;i<nums.size();i++){
                if(total+nums[i]>mid){
                    count++;
                    total=nums[i];
                }
                else{
                    total+=nums[i];
                }
            }
            if(count<=k){
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