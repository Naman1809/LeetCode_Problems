class Solution {
public:
    int trap(vector<int>& height) {
      int n=height.size();
        vector<int>left(n);
        vector<int>right(n);
        int maxi=0;
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i-1]);
        }
        maxi=0;
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i+1]);
            
        }int ans=0;
        for(int i=0;i<n-1;i++){
            int j=min(left[i],right[i])-height[i];
        if(j>0)ans+=j;
        }
    
    return ans;
    /*int leftmax=0,rightmax=0;
        int left=0,right=n-1,ans=0;
        while(left<=right){
            if(height[left]<height[right]){
                if(height[left]>leftmax)leftmax=height[left];
                else ans+=leftmax-height[left];
                left++;
            }
            else{
               if(height[right]>rightmax)rightmax=height[right];
                else ans+=rightmax-height[right];
                right--;  
            }
        }
        return ans;*/
    }
};