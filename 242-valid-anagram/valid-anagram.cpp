class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                return false;
            }
            else mp[s[i]]--;
        if(mp[s[i]]==0)mp.erase(s[i]);
        }
return mp.size()==0;
    }
};