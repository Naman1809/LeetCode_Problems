class Solution {
public:
    //  int solve(string S1, string S2, int n, int m,vector<vector<int>>&dp){
    //     if(m==0||n==0){
    //         return 0;
    //     }
    //      if(dp[n][m]!=-1){
    //          return dp[n][m];
    //      }
    //     if(S1[n-1]==S2[m-1]){
    //         return dp[n][m]= 1+solve(S1,S2,n-1,m-1,dp);
    //     }
    //     else{
    //         return dp[n][m]=max(solve(S1,S2,n-1,m,dp),solve(S1,S2,n,m-1,dp));
    //     }
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<m+1;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};