class Solution {
public:
     int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int i=0,j=n-1;
        int maxscore=0;
        int score=0;
        sort(tokens.begin(),tokens.end());
        while(i<=j)
        {
            if(tokens[i]<=power)
            {
                power-=tokens[i];
                score++;
                maxscore=max(score,maxscore);
                i++;
            }
            else if(tokens[i]>power&&score>=1)
            {
                power+=tokens[j];
                score--;
                j--;
            }
            else
            {
                break;
            }
        }
        return maxscore;  
    }
};