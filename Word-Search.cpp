class Solution {
    private:
    bool search(int i, int j ,int n, int m, vector<vector<char>>&b, string &word,int k){
        if(k==word.size()) return true;
        if(i<0 ||j<0|| i==n||j==m|| b[i][j]!=word[k]) return false;
        
        char ch=b[i][j];
        b[i][j]='#';
        bool op1=search(i-1,j,n,m,b,word,k+1);
        bool op2=search(i+1,j,n,m,b,word,k+1);
        bool op3=search(i,j+1,n,m,b,word,k+1);
        bool op4=search(i,j-1,n,m,b,word,k+1);
        b[i][j]=ch;


        return op1||op2||op3||op4;




        


    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(search(i,j,n,m,board,word,0))
                    return true;
                }

            }
        }
        return false;
        
    }
};