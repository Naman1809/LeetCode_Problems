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
        //vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            dp[0][i]=false;
        }
        for(int i=1;i<n+1;i++){
            bool flag=true;
              for(int k=1;k<=i;k++){
                if(p[k-1]!='*'){flag=false;
                                break;
                 }
            }
            
            dp[i][0]=flag;
             // dp[i][0] = dp[i-1][0] && (s[i-1] == '*');
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(p[i-1]==s[j-1]||p[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        // return solve(s,p,n,m,dp);
    return dp[n][m];
        //return helper(p,s,n,m,dp);
    }
};