class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){

            int mid=(low+high)/2;
            if(nums[mid]==target)return mid;
// ye wale step phle theek kar rha tha tu bas galti ye thi ki tu wo nhi dekh rha tha ki low aur mid wale ke beech ami target to hi high change kariyo jaise tu likh rha thaki target>nums[mid] wo theek haipar wo gurantee nhi deta ki us range ke beech mai hi hoga toaise hi neeche wla else bhi 
            if(nums[low]<=nums[mid]){
                if (nums[low] <= target && nums[mid] >= target)
        high = mid - 1; //<---step 6 
      else
        low = mid + 1;

            }
            else{
               if (nums[mid] <= target && target <= nums[high])
        low = mid + 1;
      else
        high = mid - 1;
            }
        }
        return -1;
    }
};