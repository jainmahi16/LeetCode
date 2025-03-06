class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> possibilities;
        vector<string> board(n);
        empty_board(board);
        solve_board(board, n, possibilities);
        return possibilities;
    }
private:
    void empty_board(vector<string>& board)
    {
        int max_height=board.size();
        string empty_row;
        for(int width=0; width<max_height; width++) empty_row+='.';
        for(int height=0; height<max_height; height++) board[height] = empty_row;
    }

    void solve_board(vector<string>& board, int& n, vector<vector<string>>& possibilities, int iteration=0)
    {
        if(iteration>=n) {possibilities.emplace_back(board); return;}
        for(int row=0; row<n; row++)
        {
            if(can_put(board, row, iteration))
            {
                board[row][iteration]='Q';
                solve_board(board, n, possibilities, iteration+1);
                board[row][iteration]='.';
            }
        }
    }

    bool can_put(vector<string>& board, int row, int column)
    {
        int rows=board.size(), columns=board[0].size();
        // Top left
        for(int temp_row=row, temp_column=column; temp_row>=0 and temp_column>=0; temp_row--, temp_column--)
            if(board[temp_row][temp_column]=='Q') return false;
        // Same column
        for(int temp_column=column; temp_column>=0; temp_column--)
            if(board[row][temp_column]=='Q') return false;
        // Bottom left
        for(int temp_row=row, temp_column=column; temp_row<rows and temp_column>=0; temp_row++, temp_column--)
            if(board[temp_row][temp_column]=='Q') return false;
        return true;
        
    }
};