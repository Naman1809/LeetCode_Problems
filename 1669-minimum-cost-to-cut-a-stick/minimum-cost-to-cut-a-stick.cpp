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
        vector<vector<int>>dp(l+1,vector<int>(l+1,-1));
        return helper(1,l,cuts,dp);
    }
};