class Solution {
public:
    bool check(vector<vector<char>>& board , int row ,int column ,char & c){
    
        int m=(row/3)*3,n=(column/3)*3;
        for(int i=0 ; i<9; i++){
            if(board[row][i]==c)return false;
            if(board[i][column]==c)return false; 
            
            if(board[m+(i/3)][n+(i%3)]==c)return false;
        }
        return true;
    }
    bool helper(vector<vector<char>>& board){
        for(int i=0 ; i<board.size() ; i++){
            for(int j=0; j<board[0].size() ; j++){
                if(board[i][j]=='.'){
                    for(char c='1'; c<='9';c++){
                        if(check(board , i,j ,c)){
                            board[i][j]=c;
                            if(helper(board)){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board );
    }
};