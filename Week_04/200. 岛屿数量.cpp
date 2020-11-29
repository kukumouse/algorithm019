class Solution {
public:
    void dfs(int row,int clow,vector<vector<char>>& grid){
        if (row < 0 || row > grid.size() - 1 || clow < 0 || clow > grid[0].size() - 1)
            return ;
        if (grid[row][clow] == '0')
            return ;
        grid[row][clow] = '0';
        dfs(row+1,clow,grid);
        dfs(row,clow+1,grid);
        dfs(row-1,clow,grid);
        dfs(row,clow-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int nr = 0 , cr = 0 ;
        int ans = 0 ;
        nr = grid.size();
        if (nr > 0 ){
            cr = grid[0].size();
        }
        for (int i = 0 ;i < nr ; i++){
            for (int j = 0 ; j < cr ; j++){
                if (grid[i][j] == '1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;

    }
};