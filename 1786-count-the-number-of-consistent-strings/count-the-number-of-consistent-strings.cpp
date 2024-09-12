class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
       vector<int> a(200,0);
        int i,k,count=0;
        for(i = 0;i<allowed.size();i++)
        {
            a[allowed[i]]++;
        }
        for(auto word: words)
        {
            k = word.size();
            for(i = 0 ;i<k;i++)
            {
                if(!a[word[i]])
                {
                    break;
                }
            }
            if(i==k)
                count++;
                
        }
        return count;
}
};