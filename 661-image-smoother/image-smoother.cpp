class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=img[i][j],num=1;
                if(i+1<m){
                    sum+=img[i+1][j];
                    num++;
                }
                if(i-1>=0){
                    sum+=img[i-1][j];
                    num++;
                }if(j+1<n){
                    sum+=img[i][j+1];
                    num++;
                }if(j-1>=0){
                    sum+=img[i][j-1];
                    num++;
                }if(i+1<m&&j+1<n){
                    sum+=img[i+1][j+1];
                    num++;
                }if(i+1<m&&j-1>=0){
                    sum+=img[i+1][j-1];
                    num++;
                }if(i-1>=0&&j+1<n){
                    sum+=img[i-1][j+1];
                    num++;
                }if(i-1>=0&&j-1>=0){
                    sum+=img[i-1][j-1];
                    num++;
                }
                ans[i][j]= (sum/num);
            }
        }
        return ans;
    }
};