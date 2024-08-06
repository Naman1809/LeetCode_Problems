class Solution {
public:
    int helper(int i, int n,vector<int>&dp){
        if(i>n)return 0;
        if(i==n)return dp[i]=1;
        if(dp[i]!=-1)return dp[i];
        return dp[i] = helper(i+1,n,dp) + helper(i+2,n,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        helper(0,n,dp);
        return dp[0];
    }
};