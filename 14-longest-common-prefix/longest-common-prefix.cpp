class TrieNode{
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        childCount =0;
        isTerminal = false;
    }
};

class Trie{
 public:
    TrieNode* root;
    Trie(char ch){
        root = new TrieNode(ch); 
    }
      void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';  // Adjusted for lowercase characters
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans){
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            if(root->childCount ==1){
                ans.push_back(ch);
                int index = ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal)break;
        }
    }

};


class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        
        Trie *t = new Trie('\0');

        for(int i=0;i<arr.size();i++){
            if(arr[i]=="")return "";
            t->insertWord(arr[i]);
        }

        string first = arr[0];
        string ans ="";

        t->lcp(first,ans);
        return ans;

    }   
};