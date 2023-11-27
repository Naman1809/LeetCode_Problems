class Solution {
public:
    int knightDialer(int n) {
         if(n==1)return 10;
         unordered_map<int,vector<int>>mp;
         int mod = 1e9+7;
         mp[0]={4,6};
         mp[1]={6,8};
         mp[2]={9,7};
         mp[3]={4,8};
         mp[4]={3,9,0};
         mp[6]={1,7,0};
         mp[7]={2,6};
         mp[8]={1,3};
         mp[9]={4,2};

vector<int>v(10,1);
       for(int i=2;i<=n;i++){
           vector<int>temp(10);
           for(auto [key,val] : mp){
               for(auto j : val){
                   temp[key] = (temp[key]+ v[j])%mod;
               }
           }
           v=temp;

       }
       int ans=0;
       for(auto it:v){
           ans = (ans%mod + it%mod)%mod;
       }
       return ans;

    }
};