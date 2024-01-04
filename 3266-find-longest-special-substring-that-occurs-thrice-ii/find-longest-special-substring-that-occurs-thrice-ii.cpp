class Solution {
public:
    bool isPossible(int mid, string&s,unordered_map<char,vector<int>>&mp){
        int count=0;
        for(auto it: mp){
            int key=it.first;
            vector<int>values=it.second;
            int count=0;
            for(auto val:values){
                // ye krkr dekh liyo samjh jayega man le 4 consecutive cahracer hai
                // t usme 3 length wali 2 bna payega na 4-3+1=2 aise 
                count +=max(0,val-mid+1);
            }
            if(count>=3)return true;
        }
        return false;
    }

    int maximumLength(string s) {
        unordered_map<char,vector<int>>mp;
        char lastChar=s[0];
        int count=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==lastChar){
                count++;
            }else{
                mp[lastChar].push_back(count);
                count=1;
                lastChar=s[i];
            }
        }
        mp[lastChar].push_back(count);

        int ans=-1;
        int l=1,r=s.size()-2;
        while(l<=r){
            int mid  = l + (r-l)/2;
            if(isPossible(mid,s,mp)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    
    }
};