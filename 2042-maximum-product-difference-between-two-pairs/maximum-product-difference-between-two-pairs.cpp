class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1=0,max2=-1,min1=INT_MAX,min2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max1){
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]<=max1){
                max2=max(max2,nums[i]);
            }
        }
         for(int i=0;i<nums.size();i++){
            if(nums[i]<min1){
                min2=min1;
                min1=nums[i];
            }
            else if(nums[i]<min2 ){
                min2=nums[i];
            }
        }
    return (max1*max2)-(min1*min2);
    }
};