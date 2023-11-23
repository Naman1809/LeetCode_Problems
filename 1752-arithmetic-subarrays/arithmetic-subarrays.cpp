class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

vector<bool>res;
     for(int i=0;i<l.size();i++){
         vector<int>ans;
         for(int j=l[i];j<=r[i];j++){
             ans.push_back(nums[j]);
         }
         sort(ans.begin(),ans.end());
         if(ans.size()==1){res.push_back(false);
         continue;
         }
         int d= ans[1]-ans[0];
         bool g= true;
         for(int j=1;j<ans.size();j++){
             if(ans[j]-ans[j-1]!=d){
                 g=false;
                 break;
             }
         }
         res.push_back(g);
     }
return res;
    }
};