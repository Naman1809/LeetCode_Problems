class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        vector<int>onerow(m,0),zerorow(m,0);
        vector<int>onecol(n,0),zerocol(n,0);
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(grid[i][j]==1){
            onerow[i]++;
            onecol[j]++;
        }
        else{
            zerorow[i]++;
            zerocol[j]++;
        }
    }
}
        vector<vector<int>>diff(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j]=onerow[i]+onecol[j]-zerorow[i]-zerocol[j];
                
            }
        }
        return diff;
    }
};