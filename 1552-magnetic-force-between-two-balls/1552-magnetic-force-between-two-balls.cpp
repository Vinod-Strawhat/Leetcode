class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int maxi=0;
        for(int i=0;i<position.size();i++){
            maxi=max(maxi,position[i]);
        }
        int left=1;
        int right=maxi;
        int mid=0;
        int ans=-1;
        while(left<=right){
            mid=left+(right-left)/2;
            int l=0;
            int count=1;
            for(int i=1;i<position.size();i++){
                if(position[i]-position[l]>=mid){
                    count++;
                    l=i;
                }
            }
            if(count>=m){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};