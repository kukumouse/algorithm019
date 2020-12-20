class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j){
        if (i < 0 || i > grid.size() - 1 || j < 0 || j > grid[i].size() - 1){
            return;
        }
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        bfs(grid,i,j - 1);
        bfs(grid,i,j + 1);
        bfs(grid,i + 1,j);
        bfs(grid,i - 1,j);

    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0;i < grid.size() ; i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == '1'){
                    cnt++;
                    bfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};