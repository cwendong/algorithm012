class Solution {
    private:
    void deepFirstSearch(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& used)
    {
        int rows = grid.size();
        int cloumns = grid[0].size();

        if (i < 0 || i >= rows || j < 0 || j >= cloumns || grid[i][j] == '0' || used[i][j])
        {
            return ;
        }

        used[i][j] = true;

        deepFirstSearch(i, j + 1, grid, used);
        deepFirstSearch(i, j - 1, grid, used);
        deepFirstSearch(i + 1, j, grid, used);
        deepFirstSearch(i - 1, j, grid, used);
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int result = 0;
        int rows = grid.size();
        if (rows == 0)
        {
            return 0;
        }
        int cloumns = grid[0].size();
        
        vector<vector<bool>> used(rows, vector<bool>(cloumns, false));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cloumns; ++j)
            {
                if(!used[i][j] && grid[i][j] == '1')
                {
                    deepFirstSearch(i, j, grid, used);
                    result++;
                }
            }
        }

        return result;
    }
};