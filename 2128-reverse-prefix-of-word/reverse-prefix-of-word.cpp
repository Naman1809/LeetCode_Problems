class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j=0;
        int n = word.size();
        while(j<n){
            if(word[j] == ch) break;
            j++;
        }
        if(j==n)return word;
        int i=0;
        while(i<j){
            swap(word[i++],word[j--]);
        }
        return word;
    }
};