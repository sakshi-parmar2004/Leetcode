class Solution {
public:
    int maxBottlesDrunk(int B, int E) {
        int empty_bottle = B ,full_bottle=0;
        while(empty_bottle>=E)
        {
            empty_bottle = empty_bottle-E+1;
            full_bottle++;
            E++;
        }
        return B+ full_bottle;
        
    }
};