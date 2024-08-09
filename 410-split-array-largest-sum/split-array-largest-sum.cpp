class Solution {
public:
    int helper(vector<int>&nums,int mid){
        int studentPage=0;
        int student=1;
        for(auto it :nums){
            if(studentPage+it<=mid){
                studentPage+=it;
                
            }else{
                student++;
                studentPage=it;
            }
        }
        return student;

    }

    int splitArray(vector<int>& nums, int k) {
        int maxi=0 ;
        int sum =0;
        for(auto it:nums){
            maxi=max(it,maxi);
            sum+=it;
        }
        int low = maxi,high =sum;
        while(low<=high){
            int mid  = low +(high-low)/2;
            if(helper(nums,mid)>k){
                low=mid+1;
            }else{
                high = mid-1;
            }
        } 
        return low;
    }
};