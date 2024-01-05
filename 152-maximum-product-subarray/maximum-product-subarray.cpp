class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int maxi = INT_MIN;
     int prod=1,suff=1;

     for(int i=0;i<nums.size();i++){
         prod*=nums[i];
         suff*=nums[nums.size()-1-i];
         maxi=max(prod,maxi);
         maxi=max(suff,maxi);
         if(prod==0)prod=1;
         if(suff==0)suff=1;
     }   
     return maxi;

    }
};