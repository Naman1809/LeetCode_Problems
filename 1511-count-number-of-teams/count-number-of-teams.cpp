
class Solution {
public:
int helper(int idx, int taken, int state, vector<int>&rating, vector<vector<vector<int>>>&dp){
    int n=rating.size();
    if(taken==3)return 1;
    if(dp[idx][taken][state]!=-1)return dp[idx][taken][state];
        int ans=0,ele=rating[idx];
        for(int i=idx+1;i<n;i++){
            if(state==0){
                if(ele<rating[i]){
                    ans+=helper(i,taken+1,1,rating,dp);
                }
                else if(ele>rating[i]){
                    ans+=helper(i,taken+1,2,rating,dp);

                }
            }
            else if(state==1){
                if(ele<rating[i])  ans+=helper(i,taken+1,1,rating,dp);
            }
            else if(state==2){
                if(ele>rating[i])ans+=helper(i,taken+1,2,rating,dp);
            }
        }
        return dp[idx][taken][state]=ans;
}
    int numTeams(vector<int>& rating) {
    int ans=0;  
    int n=rating.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(4,vector<int>(3,-1)));
      for(int i=0;i<=n-3;i++)
      ans += helper(i,1,0,rating,dp);
        
        return ans;
    }

};