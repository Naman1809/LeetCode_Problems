class Solution {
public:
int helper(int i, int j, int n, vector<vector<int>>&A,vector<vector<int>>&dp){
     if(i==n-1&&j>=0&&j<n){
        return dp[i][j]=A[i][j];
    }
    if(i>=n||i<0||j>=n||j<0)return INT_MAX;
   
    if(dp[i][j]!=INT_MAX)return dp[i][j];
    return dp[i][j]= A[i][j]+min(helper(i+1,j,n,A,dp),min(helper(i+1,j+1,n,A,dp),helper(i+1,j-1,n,A,dp)));
}
  int minFallingPathSum(vector<vector<int>>& A) {
  int n=A.size();
  vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
  int ans=INT_MAX;
  for(int i=0;i<n;i++){
      ans=min(ans,helper(0,i,n,A,dp));
  }
  return ans;
}
};