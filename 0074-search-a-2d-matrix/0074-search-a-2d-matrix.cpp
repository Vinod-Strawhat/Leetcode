
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int left=0;
     int right=matrix.size()-1;
        int mid=0;
     while(left<=right){
         mid=left+(right-left)/2;
         if(target>=matrix[mid][0] && target<= matrix[mid][matrix[mid].size()-1]){
             int l=0;
             int r=matrix[mid].size()-1;
             while(l<=r){
                 int m=l+(r-l)/2;
                 if(matrix[mid][m]<target){
                     l=m+1;
                 }
                 else if(matrix[mid][m]>target){
                     r=m-1;
                 }
                 else{
                     return true;
                 }
             }
             return false;
         }
         else if (target<matrix[mid][0]){
             right=mid-1;
         }
         else if(target>matrix[mid][matrix[mid].size()-1]){
             left=mid+1;
         }
     }
        return false;
        
    }
};