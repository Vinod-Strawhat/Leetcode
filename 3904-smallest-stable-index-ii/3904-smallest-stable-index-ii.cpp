class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=min(nums[i],suffix[i+1]);
        }
        int final=-1;
        for(int i=0;i<nums.size();i++){
            int ans=prefix[i]-suffix[i];
            if(ans<=k){
                final=i;
                break;
                
            }

        }
        return final;
    }
};