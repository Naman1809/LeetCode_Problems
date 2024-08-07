class Solution {
public:
      int helper( vector<int>&prices, int buy, int i,int cap,  vector<vector<vector<int>>>&dp){
    if(i==prices.size()||cap==0)return 0;
    if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
    if(buy){
        return dp[i][buy][cap]=max(helper(prices,0,i+1,cap,dp)-prices[i],helper(prices,1,i+1,cap,dp));
    }
    else{
        return dp[i][buy][cap]=max(helper(prices,1,i+1,cap-1,dp)+prices[i],helper(prices,0,i+1,cap,dp));

    }
}
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(prices,1,0,k,dp);
    }
};