class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            while(!s.empty() && nums2[i]>s.top()){
                mp[s.top()]=nums2[i];
                s.pop();
                
            }
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])!=mp.end()){
                nums1[i]=mp[nums1[i]];
            }
            else{
                nums1[i]=-1;
            }
        }
        return nums1;
    }
};