class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0;
        unordered_map<int,int> mp;
        int ans=0;
        for(int right=0;right<nums.size();right++){
            mp[nums[right]]++;
            
            if(mp[nums[right]]>k){
                while(mp[nums[right]]>k){
                    mp[nums[left]]--;
                    left++;
                }
            }
            ans=max(ans,right-left+1);
            


        }
        return ans;
    }
};