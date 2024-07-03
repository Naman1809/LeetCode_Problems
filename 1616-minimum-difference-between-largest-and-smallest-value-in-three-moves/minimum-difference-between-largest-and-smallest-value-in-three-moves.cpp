class Solution {
public:
    using VI = vector<int>;
    static constexpr int INF = 2e9 + 7;
    int minDifference(VI& A, int min = INF) {
        sort(A.begin(), A.end());
        int N = A.size(),
            i = 0,
            j = N - 4;// 
        while (0 <= j && j < N)
			min = std::min(min, A[j++] - A[i++]);
        return min < INF ? min : 0;
    }
};