class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=0;
        for(int i=1;i<=1001;i++){
            if(mp.find(k*i)==mp.end()){
                ans=k*i;
                break;
            }
        }
        return ans;
    }
};