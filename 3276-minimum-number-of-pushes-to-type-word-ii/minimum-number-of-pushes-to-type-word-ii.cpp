class Solution {
public:
    int helper(vector<char>&sc, unordered_map<char, int> &freq){
          int ans = 0;
    int kp = 1;
    int kn = 2;
    for (char ch : sc) {
        ans += freq[ch] * kp;
        if (kn < 9) {
            kn++;
        } else {
            kn = 2;
            kp++;
        }
    }
        return ans;
    }
    int minimumPushes(string word) {
         unordered_map<char, int> freq;

    for (char ch : word) {
        freq[ch]++;
    }

    vector<char> sc;
    for (const auto& entry : freq) {
        sc.push_back(entry.first);
    }

    sort(sc.begin(), sc.end(), [&](char a, char b) {
        return freq[b] < freq[a];
    });
        int ans = helper(sc,freq);

  

    return ans;
    }
};