//T.C= O(logn) S.C=O(logn) because of recursive stack
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        return ((n==1) || (n%2==0 && isPowerOfTwo(n/2)));
    }
};