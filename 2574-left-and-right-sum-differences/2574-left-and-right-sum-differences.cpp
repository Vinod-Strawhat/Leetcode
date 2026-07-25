class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ls(nums.size());
        ls[0]=0;
        for(int i=1;i<nums.size();i++){
            ls[i]=ls[i-1]+nums[i-1];
        }
        vector<int> rs(nums.size());
        rs[nums.size()-1]=0;
        for(int i=nums.size()-2;i>=0;i--){
            rs[i]=nums[i+1]+rs[i+1];
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(abs(ls[i]-rs[i]));
        }
        return ans;
    }
};