class Solution {
private:
    vector<vector<string>> res;
public:
    void dfs(int n,int row,int clo,int ld,int rd,vector<string> path){
        if (row >= n){
            this->res.push_back(path);
            return;
        }
        uint32_t bits = ~(clo | ld | rd) & (( 1 << n) - 1);
        while (bits > 0){
            uint32_t pick = bits & -bits;
            string tmp(n,'.');
            tmp[log2(pick)] = 'Q';
            path.push_back(tmp);
            dfs(n,row + 1, clo | pick, (ld | pick) << 1, (rd | pick) >> 1, path);
            path.pop_back();
            bits &= bits - 1; 
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path;
        dfs(n,0,0,0,0,path);
        return this->res;
    }
};