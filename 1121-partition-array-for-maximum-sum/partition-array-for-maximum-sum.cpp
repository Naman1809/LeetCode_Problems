class Solution {
public:
    int helper(vector<int>&arr, int k, int i, int n, vector<int>&dp){
        if(i==n)return 0;
        if(dp[i]!=-1) return dp[i];

        int maxi=INT_MIN,max_ans=INT_MIN,len=0;
        for(int j=i;j<min(n,i+k);j++){
            maxi=max(maxi,arr[j]);
            len++;
        
        int sum=(len*maxi) + helper(arr,k,j+1,n,dp);
        max_ans =max(max_ans,sum);
    }
    return dp[i] = max_ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
     int n = arr.size();
     vector<int>dp(n,-1);
     return helper(arr,k,0,n,dp);   
    }
};