class Solution {
public:
 int islandPerimeter(vector<vector<int>>& grid) {
        // int count=0, repeat=0;
        // for(int i=0;i<grid.size();i++)
        // {
        //     for(int j=0; j<grid[i].size();j++)
        //         {
        //             if(grid[i][j]==1)
        //             {
        //                 count ++;
        //                 if(i!=0 && grid[i-1][j] == 1) repeat++;
        //                 if(j!=0 && grid[i][j-1] == 1) repeat++;
        //             }
        //         }
        // }
        // return 4*count-repeat*2;
     int rows = grid.size();
        int cols = grid[0].size();
    // alternate solution counting number of edges adajcent to inside or outside water
        int num = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    if (i == 0 || grid[i - 1][j] == 0) num++; // UP
                    if (j == 0 || grid[i][j - 1] == 0) num++; // LEFT
                    if (i == rows -1 || grid[i + 1][j] == 0) num++; // DOWN
                    if (j == cols -1 || grid[i][j + 1] == 0) num++; // RIGHT
                }
            }
        }
        return num;
    }
};