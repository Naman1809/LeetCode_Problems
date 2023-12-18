class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n = grid[0].size();
        int offsets[] = {0, 1, 0, -1, 0};
        queue<pair<int,int>>q;
        int f=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if (grid[i][j]==1){
                    f++;
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            ans++;
            while(s--){
                auto p =q.front();
                q.pop();
               
                  for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                                grid[r][c] = 2;
                                f--;
                                q.push({r, c});
            }
        }
    }
        }
        if(f>0)return -1;
        else return ans==0?0:ans-1;
    }
};