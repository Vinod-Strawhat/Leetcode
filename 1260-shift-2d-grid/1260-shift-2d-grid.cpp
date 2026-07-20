class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int index=0;
        int newindex=0;
        int col,row=0;
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                index= i*n +j;
                newindex= (index+k) % (m*n);
                col=newindex % n;
                row=newindex/n;
                ans[row][col]=grid[i][j];

            }
        }
        return ans;
    }
};