class Solution {
public:
 int helper(int i, vector<int>&arr, int sum, vector<vector<int>>&dp){
    if(i>=arr.size())return 0;
    if(sum==0)return 1;
    else if(sum<0)return 0;
    if(dp[sum][i]!=-1)return dp[sum][i];
    return dp[sum][i]=(helper(i+1,arr,sum-arr[i],dp))||(helper(i+1,arr,sum,dp));
}
    bool canPartition(vector<int>& arr) {
    
        int sum=0;
        for(int i=0;i<arr.size();i++){
            
            sum+=arr[i];
        }
        if(sum%2==1){
            return false;
        }
        int N=arr.size();
        sum=sum/2;
              vector<vector<int>> dp(sum+1,vector<int>(arr.size(),-1));
        return helper(0,arr,sum,dp);
        /*for(int i=0;i<N+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    dp[i][j]==false;
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
        for(int i=1;i<N+1;i++){
            for(int j=1;j<sum+1;j++){
               if(arr[i-1]<=j){
            dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
        }
        else
        dp[i][j]=dp[i-1][j];
            
        }}
        return dp[N][sum];*/
    }
};