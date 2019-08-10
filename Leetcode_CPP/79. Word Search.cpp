class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    bool exist(vector<vector<char>>& board, string word) {
        // list all start positions
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[0].size();++j)
                if(dfs(board, word, 0, i, j)) return true;
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int sid, int x, int y){
        if(board[x][y]!=word[sid]) return false;
        else if(sid == word.size()-1) return true;
        
        char t = board[x][y];
        board[x][y] = '*';
        
        for(int i=0;i<4;++i){
            int newx = x+dx[i], newy = y+dy[i];
            if(newx>=0 && newx<board.size() && newy>=0 && newy<board[0].size())
                if(dfs(board, word, sid+1, newx, newy)) return true;
        }
        
        
        board[x][y] = t;
        return false;
        
    }
};