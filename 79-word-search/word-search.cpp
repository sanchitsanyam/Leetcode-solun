class Solution {
public:
    bool existhelper(int i , int j,vector<vector<int>>& dp ,vector<vector<char>>& board,string& word ,int index){
        int m=board.size();
        int n=board[0].size();
        if(i>=m || j>=n ||  i<0 || j<0 || dp[i][j]==0 ||board[i][j] != word[index])return false;
        
        if(index==word.size()-1)return true;
        dp[i][j]=0;
        //go down
       
        bool op1=existhelper(i+1,j,dp,board,word ,index+1);
        
        //go right
        
        bool op2=existhelper(i,j+1,dp,board,word ,index+1);
      
        //go up
       
        bool op3=existhelper(i-1,j,dp,board,word ,index+1);
       
        //go left
        
        bool op4=existhelper(i,j-1,dp,board,word ,index+1);
        
        dp[i][j]=1;
        return ((op1 || op2) || (op3|| op4));


    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1));
        
        bool op=false;
        for(int i=0;i<m ;i++){
            for(int j=0;j<n;j++){
               op=(op||existhelper(i,j,dp,board,word ,0)); 
            }
        }
        return op;
        
    }
};