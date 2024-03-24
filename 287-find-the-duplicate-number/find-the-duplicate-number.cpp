class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=0;
        int n=nums.size()-1;
        // for(int i=0;i<n;i++){
        //     s+=nums[i];
        // }
        // int g=s-((n-1)*(n))/2;
        // return g;
        // int g=0;
        // unordered_map<int,int> mp;
        // for(int i=0;i<n;i++){
        //     if(mp[nums[i]]){
        //         g=nums[i];
        //         break;
        //     }
        //     mp[nums[i]]++;
        // }
        // return g;
        // isme kar kya rhe hai ki number dekho 1 se n ki range mai hai to us number ka index change kar rhe hai agar us number ka index ki value phle se chagned mil gyi mtlb wo number phle a achuka hai
              int duplicate = -1;
        for (int i = 0; i < nums.size(); i++) {
            int cur = abs(nums[i]);
            if (nums[cur] < 0) {
                duplicate = cur;
                break;
            }
            nums[cur] *= -1;
        }
           return duplicate;

           // ye wala method isliye galt hai ki ye nhi bola ki 1 se n tak sare intergers honge ye bola hai jo integer hoga wo inke beech mai hoga to wo case to hai ki ek ek hi repeat hoga par ek case ye bhi hoga ki poore array mai ek hi umber bari bari repeat ho rha hai to us case mai galt hoga ye 
/*int ans=nums[0];
           for(int i=1;i<=n;i++){
               ans=ans^i^nums[i];
           }
           return ans;*/
    }
};