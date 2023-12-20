class Solution {
public:
    int buyChoco(vector<int>& nums, int money) {
      int min1=INT_MAX,min2=INT_MAX;
       for(int i=0;i<nums.size();i++){
            if(nums[i]<min1){
                min2=min1;
                min1=nums[i];
            }
            else if(nums[i]<min2 ){
                min2=nums[i];
            }
        }
        return (money -(min1+min2))>=0?(money -(min1+min2)):money;

    }
};