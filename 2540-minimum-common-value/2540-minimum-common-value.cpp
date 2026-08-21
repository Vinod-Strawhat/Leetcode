class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ptr1=0;
        int ptr2=0;
        //int n=max(nums1.size(),nums2.size());
        int ans=-1;
        while(ptr1<nums1.size() && ptr2<nums2.size()){
            if(nums1[ptr1]<nums2[ptr2]){
                ptr1++;
            }
            else if(nums1[ptr1]>nums2[ptr2]){
                ptr2++;
            }
            else{
                ans=nums1[ptr1];
                break;
            }
        }
        return ans;
        
    }
};