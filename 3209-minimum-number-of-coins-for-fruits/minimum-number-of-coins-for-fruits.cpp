class Solution {
public:
    int helper(int i, int free , int n, vector<int>&prices,  vector<vector<int>>&dp){
        if(i>=n)return 0;
        
if(dp[i][free]!=-1)return dp[i][free];        
        int a = prices[i]+helper(i+1,i+1,n,prices,dp);

        int b = INT_MAX;
        if(free>0)
        b=helper(i+1,free-1,n,prices,dp);
        
        

        return dp[i][free]=min(a,b);
    }
    int minimumCoins(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(0,0,n,prices,dp);
    }
};