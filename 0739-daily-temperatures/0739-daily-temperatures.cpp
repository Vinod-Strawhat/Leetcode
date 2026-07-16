class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            while(!s.empty() && nums[i]>nums[s.top()]){
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};