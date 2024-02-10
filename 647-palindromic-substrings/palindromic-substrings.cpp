class Solution {
public:
int helper(string &s, int i, int j,vector<vector<int>>&dp){
    if(i>j)return 1;
    if(dp[i][j]!=-1){
return dp[i][j];
    }
if(s[i]==s[j])return dp[i][j]=helper(s,i+1,j-1,dp);
else return dp[i][j]=0;

}
    int countSubstrings(string s) {
        int ans=0;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                ans+=helper(s,i,j,dp);
            }
        }
        return ans;
    }
};