class Solution {
public:
    int findClosest(int x, int y, int z) {
        int val1 = abs(x-z) , val2=abs(y-z);
        if(val1==val2)
        {
            return 0;
        }
        else if(val1<val2)
        {
            return 1;
        }
        else
        {
            return 2;
        }
        

        
    }
};