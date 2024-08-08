class Solution {
public:

    int helper(int i, int j, vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        int mini = INT_MAX;
        for(int k=i;k<=j;k++){
            int ans = cuts[j+1]-cuts[i-1] + helper(i,k-1,cuts,dp) + helper(k+1,j,cuts,dp);
            mini = min(ans, mini);
        }
        return dp[i][j]=mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int l =cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        // vector<vector<int>>dp(l+1,vector<int>(l+1,-1));
        vector<vector<int>>dp(l+2,vector<int>(l+2,0));

        for(int i = l;i>=1;i--){
            for(int j=1;j<=l;j++){
                if(i>j)continue;
                 int mini = INT_MAX;
        for(int k=i;k<=j;k++){
            int ans = cuts[j+1]-cuts[i-1] + dp[i][k-1]+ dp[k+1][j];
            mini = min(ans, mini);
        }
        dp[i][j] = mini;
            }
        }
        return dp[1][l];
        // return helper(1,l,cuts,dp);
    }
};