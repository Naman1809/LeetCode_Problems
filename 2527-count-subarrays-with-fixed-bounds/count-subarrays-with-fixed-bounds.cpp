// class Solution {
// public:
//     long long helper(vector<int>& nums,int si,int ei,int minK,int maxK){
//            vector<int> mink,maxk;  
//         for(int i =si;i<=ei;i++){
//             if(nums[i]== minK)mink.push_back(i);
//             if(nums[i]== maxK)maxk.push_back(i); }
        
//         long long res=0;
//         for(int i=si;i<=ei;i++){
//             auto a = lower_bound(mink.begin(),mink.end(),i);
//             auto b = lower_bound(maxk.begin(),maxk.end(),i);
//                if(a==mink.end()||b == maxk.end() )continue;
//         int x = *(a) ;
//         int y = *(b);
//         int v = max(x,y);
//         res+= (ei-v+1); }
//         return res;  
        
//     }
    
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
//         int l=-1,r=-1;
//         long long n=nums.size();
//         long long ans=0;
//         for(int i=0;i<n;i++){
//             if(nums[i]>=minK&&nums[i]<=maxK){
//                 if(l==-1)l=i;
//                 r=i;
//             }
//             else{
//                 if(l!=-1){
//                     ans+=helper(nums,l,r,minK,maxK);
//                 }
//                 l=-1,r=-1;
//             }
//         }
//  if(l!=-1){
//                     ans+=helper(nums,l,r,minK,maxK);
//                 }
//     return ans;
//     }
// };
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0;
        bool minFound = false, maxFound = false;
        int start = 0, minStart = 0, maxStart = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num < minK || num > maxK) {
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            if (num == minK) {
                minFound = true;
                minStart = i;
            }
            if (num == maxK) {
                maxFound = true;
                maxStart = i;
            }
            if (minFound && maxFound) {
                res += (min(minStart, maxStart) - start + 1);
            }
        }
        return res;
    }
};