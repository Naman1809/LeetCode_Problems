class Solution {
public:
    int helper(int i, vector<int>&prices, int buy, int n,vector<vector<int>>&dp){
        if(i==n)return 0;

        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(helper(i+1,prices,0,n,dp)-prices[i], helper(i+1,prices,1,n,dp));
        }
        else{
            return dp[i][buy]=max(helper(i+1,prices,1,n,dp)+prices[i],helper(i+1,prices,0,n,dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int  n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,prices,1,n,dp);
    }
};