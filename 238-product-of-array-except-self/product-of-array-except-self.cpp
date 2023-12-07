class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pre=nums;
        vector<int>suf=nums;
        vector<int>ans=nums;

        
        pre[0]=nums[0];
        int n=nums.size();
        suf[n-1]=nums[n-1];
        // int s=nums[n-1];
        for(int i=1;i<n;i++){
         pre[i]=nums[i]*pre[i-1];
            // p=nums[i]*p;
            // pre[i]=p;

        }
        for(int i=n-2;i>=0;i--){
            suf[i]=nums[i]*suf[i+1];
        }
        ans[n-1]=pre[n-2];
        ans[0]=suf[1];
        for(int i=1;i<n-1;i++){
            ans[i]=pre[i-1]*suf[i+1];
        }
        return ans;
    }
};