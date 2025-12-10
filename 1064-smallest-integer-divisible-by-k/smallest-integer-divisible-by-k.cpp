class Solution {
public:
    int smallestRepunitDivByK(int k) {

        int num =0;
        int count=0;
        while(num<INT_MAX)
        {
            num=(num*10+ 1)%k;
            count++;
            if(num==0)return count;
            if(count>k)return -1;
        }
        return -1;
        
    }
};