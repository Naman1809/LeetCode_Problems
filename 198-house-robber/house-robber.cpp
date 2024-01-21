class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return arr[0];
       // vector<int>dp(n);
        int prev1=arr[0];
        int prev2=0;
        // dp[0]=arr[0];
        // dp[1]=max(arr[0],arr[1]);
        for(int i=1;i<n;i++){
            
            int a=arr[i];
            if(i>1)a+=prev2;
            int b=prev1;
           int curr=max(a,b);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};