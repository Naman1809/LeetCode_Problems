// class Solution {
// public:
//     vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//         vector<vector<int>>ans;
//         int a1=0,b1=0,a2=0,b2=0;
//         int m=land.size();
//         int n=land[0].size();
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(land[i][j]==1){
//                     a1=a2=i;
//                     b1=b2=j;
//                     land[i][j]=0;
//                     queue<pair<int,int>>q;
//                     q.push({i,j});
//                     while(!q.empty()){
//                         pair<int,int>p=q.front();
//                         q.pop();
//                         int r=p.first,c=p.second;
//                         if(r-1>=0&&land[r-1][c]==1){
//                             q.push({r-1,c});
//                             land[r-1][c]=0;
//                             a1=r-1;
//                         }
//                           if(r+1<m&&land[r+1][c]==1){
//                             q.push({r+1,c});
//                             land[r+1][c]=0;
//                             a2=r+1;
//                         }
//                             if(c-1>=0&&land[r][c-1]==1){
//                             q.push({r,c-1});
//                             land[r][c-1]=0;
//                                 //cout<<land[r][c-1];
//                             b1=c-1;
//                         }    if(c<n&&land[r][c+1]==1){
//                             q.push({r,c+1});
//                             land[r][c+1]=0;
//                             b2=c+1;
//                         }
//                     }
//                 vector<int>ans1;
//     ans1.push_back(a1);
//     ans1.push_back(b1);
//     ans1.push_back(a2);
//     ans1.push_back(b2);
//                 //    cout<<1<<endl;
// ans.push_back(ans1);
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    void fill(vector<vector<int>>&land,int i,int j,int r1,int c1)// function to make visited 1's zero so that i dont travel them again
    {
        for(int x=i;x<r1;x++)
        {
            for(int y=j;y<c1;y++)
            {
                land[x][y]=0;
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
    int m=land.size();
    int n=land[0].size();
    vector<vector<int>>ans;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(land[i][j]==0)
            {
                continue;
            }
            if(land[i][j]==1)
            {
                int r1=i;
                int c1=j;
                while(r1<m&&land[r1][j]==1)r1++;
                while(c1<n&&land[i][c1]==1)c1++;
                fill(land,i,j,r1,c1);
                ans.push_back({i,j,r1-1,c1-1});
            }
        }
    }
        return ans;
    }
};