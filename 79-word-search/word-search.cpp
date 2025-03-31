class Solution {
public:
    bool dfs(vector<vector<char>>& board,string word,vector<vector<int>>& vis,int ind,int row,int col){
        if(ind==word.size()) return true;
        vis[row][col]=1;
        int delrow[]={0,1,0,-1};
        int delcol[]={1,0,-1,0};
        for(int i=0;i<4;i++){
            int rown=row+delrow[i];
            int coln=col+delcol[i];
            if(rown<board.size() && rown>=0 && coln<board[0].size() && coln>=0 && board[rown][coln]==word[ind] && !vis[rown][coln]){
                if(dfs(board,word,vis,ind+1,rown,coln)==true) return true;
            }
        }
        vis[row][col]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,vis,1,i,j)==true) return true;
                }
            }
        }
        return false;
    }
};