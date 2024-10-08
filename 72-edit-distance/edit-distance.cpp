class Solution {
public:
    int minDistance(string text1, string text2) {
         int n=text1.length();
        int m=text2.length();
          if(text1==text2)return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<n+1;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<m+1;j++){
            dp[0][j]=j;
        }
        // dp[0][0]=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};