class Solution {
public:

    int helper(int i, int j, vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int maxi =0;
        
        for(int k=i;k<=j;k++){
            int ans = nums[i-1]*nums[k]*nums[j+1] + helper(i,k-1,nums,dp)+ helper(k+1,j,nums,dp);
            maxi = max(maxi,ans);
        }
        return dp[i][j]=maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int i = n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j)continue;
                 int maxi = 0;
        for(int k=i;k<=j;k++){
            int ans = nums[j+1]*nums[k]*nums[i-1] + dp[i][k-1]+ dp[k+1][j];
            maxi = max(ans, maxi);
        }
        dp[i][j] = maxi;
            }
        }
        return dp[1][n];
        // return helper(1,n,nums,dp);
    }
};