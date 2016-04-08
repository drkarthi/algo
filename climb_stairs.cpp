class Solution {
public:
    int climbStairs(int n) {
        int w, w1 = 0, w2 = 1, i;         // for n=1 and n=2 stairs respectively
        for(i=1; i<=n; i++){
            w = w1 + w2;
            // prepare for the next loop
            w1 = w2;
            w2 = w;
        }
        return w;
    }
};