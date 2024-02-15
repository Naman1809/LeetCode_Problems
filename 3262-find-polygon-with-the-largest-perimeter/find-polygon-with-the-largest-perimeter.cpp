class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     long long sum =0,ans=0;
     sum = nums[0]+ nums[1];
     for(int i=2;i<nums.size();i++){
         if(sum>nums[i]){
             ans=sum;
             ans+=nums[i];
         }
         sum+=nums[i];
     }   
     return ans = ans==0?-1:ans;
    }
};