class Solution {
public:
    int mirrorDistance(int n) {

        int new_n=n,rev=0;
        while(new_n>0)
        {
            int rem = new_n%10;
            rev=rev*10 + rem;
            new_n/=10;
        }
        return abs(n-rev);
    }
};