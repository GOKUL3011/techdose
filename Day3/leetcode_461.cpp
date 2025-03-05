class Solution {
public:
    int hammingDistance(int x, int y) {
        int a=x^y;
        return __builtin_popcount(a);
    }
};
