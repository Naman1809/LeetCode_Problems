#include<bits/stdc++.h>
class Solution {
public:
    int solve(int i, int prev_ind, vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size())return 0;
        if(dp[i][prev_ind+1]!=-1)return dp[i][prev_ind+1];
        int len=solve(i+1,prev_ind,nums,dp);
        if(prev_ind==-1||nums[prev_ind]<nums[i])
            len=max(len,1+solve(i+1,i,nums,dp));
        return dp[i][prev_ind+1]=len;
    }
    
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
         return solve(0,-1,nums,dp);
        // for(int i=n-1;i>=0;i--){
        //     for(int prev_ind=i-1;prev_ind>=-1;prev_ind--){
        //          int len=dp[i+1][prev_ind+1];
        // if(prev_ind==-1||nums[prev_ind]<nums[i])
        //     len=max(len,1+dp[i+1][i+1]);
        //  dp[i][prev_ind+1]=len;
        //     }
        // }
        // return dp[0][0];
        // return solve(0,-1,nums,dp);
        
//         vector<int> ahead(n+1,0),curr(n+1,0);
//           for(int i=n-1;i>=0;i--){
//             for(int prev_ind=i-1;prev_ind>=-1;prev_ind--){
//                  int len=ahead[prev_ind+1];
//         if(prev_ind==-1||nums[prev_ind]<nums[i])
//             len=max(len,1+ahead[i+1]);
//          curr[prev_ind+1]=len;
//             }
//               ahead=curr;
//         }
//         return curr[0];
        
        // vector<int> dp(n,1);
        // int maxi=1;
        // for(int i=0;i<n;i++){
        //     for(int prev_ind=0;prev_ind<i;prev_ind++){
        //         if(nums[prev_ind]<nums[i]){
        //             dp[i]=max(dp[i],1+dp[prev_ind]);
        //         }
        //     }
        //     maxi=max(maxi,dp[i]);
        // }
        // return maxi;
        // vector<int>temp;
        // int len=1;
        // temp.push_back(nums[0]);
        // for(int i=1;i<n;i++){
        //     if(nums[i]>temp.back()){
        //         temp.push_back(nums[i]);
        //         len++;
        //     }
        //     else{
        //         int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
        //         temp[ind]=nums[i];
        //     }
        // }
        // return len;
    }
};