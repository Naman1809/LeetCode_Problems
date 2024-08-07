class Solution {
public:
int helper(vector<int>&coins, int i, int amount,vector<vector<int>>&dp){
    if(amount ==0)return 0;
     if(i==coins.size()){
     return INT_MAX -1;
    }
    if(dp[i][amount]!=-1)return dp[i][amount];
    if(coins[i]<=amount){
        return dp[i][amount] = min(1+helper(coins,i,amount-coins[i],dp),helper(coins,i+1,amount,dp));
    }
    else{
        return dp[i][amount] = helper(coins,i+1,amount,dp);
    }
}
    int coinChange(vector<int>& coins, int amount) {
                vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));

        return helper(coins,0,amount,dp)==INT_MAX-1?-1:helper(coins,0,amount,dp);
    }
};