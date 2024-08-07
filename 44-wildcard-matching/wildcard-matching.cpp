class Solution {
public:
    bool helper(string &p, string &s, int n, int m,vector<vector<int>>&dp){
        if(n==0 && m==0)return true;
        if(n==0 && m>0) return false;
        if(m==0 && n>0){
            for(int i=1;i<=n;i++){
                if(p[i-1]!='*')return false;
            }
            return true;
        }

        if(dp[n][m]!=-1)return dp[n][m];
        if(p[n-1] == s[m-1]|| p[n-1] == '?'){
            return dp[n][m]=helper(p,s,n-1,m-1,dp);
        }
        else if(p[n-1] == '*'){
            return dp[n][m]=helper(p,s,n-1,m,dp) || helper(p,s,n,m-1,dp);
        }
        return dp[n][m]=false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(p,s,n,m,dp);
    }
};