class Solution {
public:
int helper(vector<int>& nums, int goal){
    int i=0,j=0,ans=0,n=nums.size(),sum=0;
    if(goal<0)return 0;
    while(j<n){
      sum+=nums[j];
      while(sum>goal){
          sum-=nums[i];
          i++;

      }  
      ans+=(j-i+1);
      j++;
    }
    return ans;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      // ye wala to O(N) space mai ho gya
      /*  unordered_map<int,int>mp;
        mp[0]=1;
        int pS=0, count=0;
        
        for(int i=0;i<nums.size();i++)
        {
            pS+=nums[i];
            if(mp[pS-goal])
                count+=mp[pS-goal];
            mp[pS]++;
        }
        return count;
    */
    // aab krte hai sliding window se krte hai
// dekho jo helper function hai wo dega utne subarrays jinka maximum sum goal haipar isme wo wlae subarray bhi to add ho jayeggne na jinka sum goal se kam hai islie goal se goal-1 wale sum ke subarrsy wala anser ko minus kar diya to sirf utehi subarray sbach jayenge jinka sum goal ke equal hai
    return helper(nums,goal)-helper(nums,goal-1);
    }
};