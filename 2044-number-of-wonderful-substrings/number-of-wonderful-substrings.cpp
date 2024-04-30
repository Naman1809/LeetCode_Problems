class Solution {
public:
    long long wonderfulSubstrings(string word) {
      int len=word.length();
        unordered_map<string, int>mp; // key -> count string and value is it's frequency.
        string temp="0000000000";
        long long ans=0;
        mp[temp]=1;
        for(int i=0;i<len;i++)
        {
           temp[word[i]-'a']= temp[word[i]-'a']=='0'?'1':'0';
            if(mp.find(temp)!=mp.end())
            {
                ans+=mp[temp];
            }
            mp[temp]++;
            for(int j=0;j<10;j++)
            {
                string t=temp;
                t[j]=t[j]=='0'?'1':'0';
                if(mp.find(t)!=mp.end())
                    ans+=mp[t];
            }
        }
        return ans;
    }
};
