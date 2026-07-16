class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix[0].size()-1;
        int left=matrix[0][0];
        int right=matrix[n][n];
        int mid=0;
        int ans=0;
        while(left<=right){
            mid=left+(right-left)/2;
            int i=n;
            int j=0;
            int count=0;
            
            while(i>=0 && j<=n){
                if(matrix[i][j]>mid){
                    i--;
                }
                else if(matrix[i][j]<=mid){
                    count+=i+1;
                    j++;
                }
            }
            if(count<k){
                left=mid+1;
            }
            else if(count>=k){
                ans=mid;
                right=mid-1;
            }
           

        }
        return ans;
    }
};