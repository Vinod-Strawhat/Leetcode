class Solution {
public:
    bool safe(vector<string> &board,int row,int col,int n){
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }
        for(int j=0;j<n;j++){
            if(board[j][col]=='Q'){
                return false;
            }
        }
        //left  up diagonal 
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        //right up diagonal
        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void Nqueen(vector<string> &board,int row,int n,vector<vector<string>> &ans){
        if(row==n){
            ans.push_back({board});
            return;
        }

        for(int j=0;j<n;j++){
            if(safe(board,row,j,n)){
                board[row][j]='Q';
                Nqueen(board,row+1,n,ans);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        Nqueen(board,0,n,ans);
        return ans;

    }
};