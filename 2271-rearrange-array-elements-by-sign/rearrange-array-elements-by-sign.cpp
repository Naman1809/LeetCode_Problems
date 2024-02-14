class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
   /*  vector<int>ans, ans1,ans2;
     for(int i=0;i<nums.size();i++){
         nums[i]>0?ans1.push_back(nums[i]):ans2.push_back(nums[i]);
     }  


for(int i=0;i<ans1.size();i++){
    ans.push_back(ans1[i]);
    ans.push_back(ans2[i]);

}   
return ans;  */
int n1=nums.size();
vector<int>ans(n1,0);
int p=0,n=1;
for(int i=0;i<n1;i++){
    if(nums[i]>0){
        ans[p]=nums[i];
        p+=2;
    }
    else{
        ans[n]=nums[i];
        n+=2;
    }

}
return ans;

    }
};