class Solution {
public:
    
int helper( vector<int>&prices, int buy, int i,vector<vector<int>>&dp){
    if(i>=prices.size())return 0;
    if(dp[i][buy]!=-1)return dp[i][buy];
    if(buy){
        return dp[i][buy]=max(helper(prices,0,i+1,dp)-prices[i],helper(prices,1,i+1,dp));
    }
    else{
        return dp[i][buy]=max(helper(prices,1,i+2,dp)+prices[i],helper(prices,0,i+1,dp));

    }
}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,-1));
        return helper(prices,1,0,dp);
    }
};