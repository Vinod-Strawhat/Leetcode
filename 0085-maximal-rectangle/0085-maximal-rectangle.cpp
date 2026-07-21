class Solution {
public:
    int largestrectangle(vector<int>& heights) {
        int n=heights.size();
        vector<int> right(n);
        stack<int> s;
        //right smaller element
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                right[i]=n;
            }
            else{
                right[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        vector<int> left(n);
        //left smalller element
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=-1;
            }
            else{
                left[i]=s.top();
            }
            s.push(i);
        }
        int ans=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            int curr = heights[i] * (right[i] - left[i] - 1);
            ans=max(ans,curr);
        }
        return ans;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi=0;
        int ans=0;
        int row=matrix.size();
        int cols=matrix[0].size();
        vector<int> heights(cols,0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            ans=largestrectangle(heights);
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};