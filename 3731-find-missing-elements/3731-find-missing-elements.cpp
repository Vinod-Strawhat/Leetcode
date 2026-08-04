class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=nums[0];
        vector<int> ans;
        int end=nums[nums.size()-1];
        for(int i=start;i<=end;i++){
            if(find(nums.begin(),nums.end(),i)==nums.end()){
                ans.push_back(i);
            }
        }

    return ans;
    }
};