class Solution {
public:
// dekh ye wala helper tune khud likh liya bas whi karna hai sime ki ye answer na k tak ke sare ka dega exactly ka ka nhi to whi jo sheet mai sse upar wala questions tha na wasie kar liyo ki k-1 minus krke
  int helper(vector<int>&nums, int k){
      int i=0,j=0,n=nums.size(),ans=0;
        while(j<n){
            if(nums[j]%2)k--;
            while(k<0){
                if(nums[i]%2)k++;

                i++;
            }
             ans+=(j-i+1);
            j++;
        }
        return ans;
  }/*
  // nhi samjh aaya upar wala to ye wala whi binary sum wlaa questions hai sheet mai sse upar tha jo bas usko convert kra hai isme hamne odd number ko 1 se replace kar diya aur even nuber ko 0 se baki whi hai jo upar tha
int helper(vector<int>&nums, int goal){
    if(goal<0)return 0;
    int i=0, n=nums.size(),sum=0, j=0,ans=0;
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
}*/
    int numberOfSubarrays(vector<int>& nums, int k) {
     /*   int i=0,j=0,n=nums.size(),ans=0;
        while(j<n){
            if(nums[j]%2)k--;
            while(k<0){
                if(nums[i]%2)k++;

                i++;
            }
            if(k==0)ans++;
            // ans+=(j-i+1);
            j++;
        }
        return ans;*/
      /*  for(int i=0;i<nums.size();i++){
            if(nums[i]%2)nums[i]=1;
            else nums[i]=0;
        }*/
            return helper(nums,k)-helper(nums,k-1);
 
    }
};