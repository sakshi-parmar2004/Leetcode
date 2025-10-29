class Solution {
public:
    int smallestNumber(int n) {
        
        //the reprentaion of np. with set bits is n=2^b -1;
        int b = log2(n)+1;
        return (1<<b )-1;
    }
};