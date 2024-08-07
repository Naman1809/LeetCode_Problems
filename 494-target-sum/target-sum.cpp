class Solution {
public:
// int count(vector<int> nums, int n, int s, vector<vector<int>>&dp){
//     if(n==0){
//         if(s==0){
//             return 1;
//         }
//         return 0;
//     }
//     if(dp[n][s]!=-1){return dp[n][s];}
//     if(nums[n-1]<=s){
//         return dp[n][s]=count(nums,n-1,s-nums[n-1],dp)+count(nums,n-1,s,dp);
//     }
//     else{
//         return dp[n][s]=count(nums,n-1,s,dp);
//     }
// }
    
    int answer(vector<int>&nums, int n, int s){
        int dp[n+1][s+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<s+1;j++){
                if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
            }
            
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<s+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][s];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
int sum=0;
        target=abs(target);
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum<target||(sum+target)%2)return 0;
        int s=(sum+target)/2;
        // vector<vector<int>>dp(n+1,vector<int>(s+1),-1);
        // return count(nums,n,s,dp);
 return answer(nums,n,s);
    }
};