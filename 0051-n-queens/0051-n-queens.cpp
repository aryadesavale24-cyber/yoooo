class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board,int n){
        for(int i=0;i<n;i++){
            if(board[row][i]=='Q') return false;
        }
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
        }
        for(int i=row,j=col;i>=0&&j>=0;j--,i--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;

    }
    void f(int row,int n,vector<string>&board, vector<vector<string>>&ans){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(row,j,board,n)){
                board[row][j]='Q';
                f(row+1,n,board,ans);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        f(0,n,board,ans);
        return ans;

        
    }
};