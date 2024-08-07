class Solution {
public:
    int helper(int i, vector<int>coins, int amount, vector<vector<int>>&dp){
        if(i==0){
            return amount%coins[0]==0;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int nottake = helper(i-1,coins,amount,dp);
        int take=0;
        if(coins[i]<=amount){
            take = helper(i,coins,amount-coins[i],dp);
        }
        return dp[i][amount] = take + nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(n-1,coins,amount,dp);
    }
};